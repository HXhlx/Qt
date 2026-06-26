#include "Worker.h"
#include "DatabaseManager.h"
#include "CryptoHelper.h"

Worker::Worker(QWidget* parent, QString name, QString password)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	// 使用参数化查询验证登录
	QSqlQuery query = DatabaseManager::instance().createQuery();
	QString sql = "SELECT * FROM worker WHERE Name = :name";
	QVariantMap params;
	params[":name"] = name;
	
	if (DatabaseManager::instance().executeQuery(query, sql, params))
	{
		while (query.next())
		{
			QString storedHash = query.value("Password").toString();
			QString salt = query.value("Salt").toString();
			
			// 验证密码
			if (CryptoHelper::verifyPassword(password, storedHash, salt))
			{
				WorkerID = query.value("WorkerID").toULongLong();
				Name = name;
				Password = password;
				ID = query.value("WorkIDCard").toString();
				age = query.value("WorkAge").toUInt();
				time = query.value("Experience").toULongLong();
				state = query.value("Statement").toString();
				phone = query.value("WorkPhone").toString();
			}
		}
	}
	
	Show();
	opentable();
	setCentralWidget(ui.tabWidget);
}

Worker::~Worker()
{
}

void Worker::opentable()
{
	table = new QSqlRelationalTableModel(this, DatabaseManager::instance().database());
	table->setTable("order");
	table->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
	table->setFilter(QString("WorkerID='%1'").arg(WorkerID));
	if (!(table->select()))
	{
		QMessageBox::critical(this, "错误", table->lastError().text());
		return;
	}
	QStringList strs;
	strs << "订单号" << "开始时间" << "完成时间" << "车牌号" << "商标" << "型号" << "账号" << "描述" << "工号" << "价格";
	for (int i = 0; i < strs.count(); i++)table->setHeaderData(i, Qt::Horizontal, strs[i]);
	select = new QItemSelectionModel(table);
	ui.orderView->setModel(table);
	ui.orderView->setSelectionModel(select);
	ui.orderView->setColumnHidden(6, true);
	ui.orderView->setColumnHidden(8, true);
}

void Worker::Show()
{
	ui.Age->setValue(age);
	ui.name->setText(Name);
	ui.phone->setText(phone);
	ui.ID->setText(ID);
	ui.timeBox->setValue(time);
	ui.WorkerID->setText(QString::number(WorkerID));
	if (state == "空闲中")ui.comboBox->setCurrentIndex(0);
	else if (state == "维修中")ui.comboBox->setCurrentIndex(1);
	ui.Save->setEnabled(false);
	ui.Cancel->setEnabled(false);
}

void Worker::on_name_textEdited(const QString& arg)
{
	ui.Save->setEnabled(true);
	ui.Cancel->setEnabled(true);
}

void Worker::on_ID_textEdited(const QString& arg)
{
	ui.Save->setEnabled(true);
	ui.Cancel->setEnabled(true);
}

void Worker::on_phone_textEdited(const QString& arg)
{
	ui.Save->setEnabled(true);
	ui.Cancel->setEnabled(true);
}

void Worker::on_Age_textEdited(const QString& arg)
{
	ui.Save->setEnabled(true);
	ui.Cancel->setEnabled(true);
}

void Worker::on_comboBox_currentIndexChanged(const QString& arg)
{
	ui.Save->setEnabled(true);
	ui.Cancel->setEnabled(true);
}

void Worker::on_Save_clicked()
{
	Name = ui.name->text();
	ID = ui.ID->text();
	time = ui.timeBox->value();
	state = ui.comboBox->currentText();
	
	// 使用参数化查询
	QSqlQuery query = DatabaseManager::instance().createQuery();
	QString sql = "UPDATE worker SET Name = :name, WorkIDCard = :id, WorkAge = :age, "
	              "Experience = :exp, Statement = :state WHERE WorkerID = :wid";
	QVariantMap params;
	params[":name"] = Name;
	params[":id"] = ID;
	params[":age"] = age;
	params[":exp"] = static_cast<quint64>(time);
	params[":state"] = state;
	params[":wid"] = WorkerID;
	
	if (!DatabaseManager::instance().executeQuery(query, sql, params))
	{
		QMessageBox::critical(this, "保存失败", DatabaseManager::instance().lastError());
		return;
	}
	QMessageBox::information(this, "保存", "保存成功!");
	ui.Save->setEnabled(false);
	ui.Cancel->setEnabled(false);
}

void Worker::on_Cancel_clicked()
{
	Show();
}

void Worker::on_Finish_clicked()
{
	QModelIndex index = select->currentIndex();
	QSqlRecord record = table->record(index.row());
	record.setValue(2, QDateTime::currentDateTime());
	table->setRecord(index.row(), record);
	state = "空闲中";
	
	// 使用参数化查询
	QSqlQuery query = DatabaseManager::instance().createQuery();
	QString sql = "UPDATE worker SET Statement = :state WHERE WorkerID = :wid";
	QVariantMap params;
	params[":state"] = state;
	params[":wid"] = WorkerID;
	DatabaseManager::instance().executeQuery(query, sql, params);
}

void Worker::on_orderCancel_clicked()
{
	QModelIndex index = select->currentIndex();
	QSqlRecord record = table->record(index.row());
	
	// 使用参数化查询查找其他空闲员工
	QSqlQuery query = DatabaseManager::instance().createQuery();
	QString sql = "SELECT WorkerID FROM worker WHERE WorkerID != :wid AND Statement = '空闲中' "
	              "ORDER BY Experience LIMIT 1";
	QVariantMap params;
	params[":wid"] = WorkerID;
	
	if (DatabaseManager::instance().executeQuery(query, sql, params))
	{
		query.next();
		record.setValue(8, query.value(0).toULongLong());
	}
	
	table->setRecord(index.row(), record);
	table->removeRow(index.row());
	time += 1;
	state = "空闲中";
	
	// 更新员工状态
	sql = "UPDATE worker SET Statement = :state, Experience = :exp WHERE WorkerID = :wid";
	params.clear();
	params[":state"] = state;
	params[":exp"] = static_cast<quint64>(time);
	params[":wid"] = WorkerID;
	DatabaseManager::instance().executeQuery(query, sql, params);
}

void Worker::on_orderView_clicked()
{
	QModelIndex index = select->currentIndex();
	QSqlRecord record = table->record(index.row());
	if (record.value(2).isNull())ui.Finish->setEnabled(true);
	else ui.Finish->setEnabled(false);
}
