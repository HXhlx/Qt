
-- DMC dump 1.0.0
-- ------------------------------------------------------
    
-- ----------------------------
-- Table structure for administrator
-- ----------------------------
    
DROP TABLE IF EXISTS `administrator`;
      
CREATE TABLE `administrator` (
  `Name` varchar(30) NOT NULL,
  `Password` varchar(100) NOT NULL,
  PRIMARY KEY (`Name`),
  UNIQUE KEY `Administrator_Name_uindex` (`Name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
      
INSERT INTO `administrator` (`Name`,`Password`) VALUES ('admin','123456');
INSERT INTO `administrator` (`Name`,`Password`) VALUES ('hx','hx19990627');
INSERT INTO `administrator` (`Name`,`Password`) VALUES ('root','123456');
-- ----------------------------
-- Table structure for car
-- ----------------------------
    
DROP TABLE IF EXISTS `car`;
      
CREATE TABLE `car` (
  `Brand` varchar(30) NOT NULL,
  `Model` varchar(30) NOT NULL,
  `Type` varchar(30) DEFAULT NULL,
  `Price` bigint(20) DEFAULT '0',
  PRIMARY KEY (`Model`,`Brand`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
      
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('ATS','A','普通',102400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('Birdy K','A','普通',96000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('superQ','A','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('WeStar','A','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('乐魂骑士','A','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('单身情歌','A','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('夜冥幽魂','A','普通',120000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('幻影绅士','A','普通',78400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('开拓者','A','普通',104000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('时光威酷','A','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('正义队长','A','普通',78400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('沙漠灵狐','A','普通',78400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('滴滴Taxi','A','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('灵动行者','A','普通',78400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('烽火战刀','A','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('狂飙旋风','A','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('疾风','A','普通',110400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('白金威酷','A','普通',78400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('空间穿梭','A','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('纪念黄金BK','A','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('蝰蛇','A','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('迷彩阿波罗','A','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('铁血阿瑞斯','A','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('阿波罗','A','普通',110400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('阿瑞斯','A','普通',126400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('C3-XR','B','普通',7040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('MINI','B','普通',4000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('北极光\r\n','B','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('威驰','B','普通',15040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('新福克斯','B','普通',40000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('新科鲁兹','B','普通',48888);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('独角兽','B','普通',78400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('男爵','B','普通',64000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('罗技G速','B','普通',30000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('致炫','B','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('英朗XT','B','普通',36000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('赛利亚','B','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('锐风','B','普通',32000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('黄金威酷','B','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('威酷','C','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('歌斯特','C','普通',18000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('萌萌','C','普通',10000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('C3-XRf','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('Jstar','RA','R系',78400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('Kmoon','RA','R系',78400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('Sunny','RA','R系',102400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('X-战车','RA','R系',239040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('三昧真火','RA','R系',175040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('丰田86','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('亡灵猎手','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('光电游侠','RA','R系',311040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('全新福克斯','RA','R系',48888);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('冲刺流星','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('凌云','RA','R系',78400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('凌锋','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('凤翎','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('加勒比','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('化身','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('南瓜小子','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('双子座','RA','R系',231040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('双鱼座','RA','R系',231040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('哥谭骑士','RA','R系',231040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('嗜血爵士','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('土豪','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('地狱男爵','RA','R系',216000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('处女座','RA','R系',231040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('复苏之风','RA','R系',159920);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('夏夜魅影','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('天启','RA','R系',135040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('天秤座','RA','R系',231040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('天蝎座','RA','R系',231040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('天行者','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('守望者','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('寒夜','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('寒星','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('射手座','RA','R系',231040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('巨蟹座','RA','R系',231040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('幻影猎手','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('幽魂之刃','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('开路先锋','RA','R系',159920);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('征服者','RA','R系',110400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('急先锋','RA','R系',102400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('拜月','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('捍卫者','RA','R系',78400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('摩羯座','RA','R系',231040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('斗士','RA','R系',96000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('时空舞者','RA','R系',294400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('星梦','RA','R系',126400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('星爵','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('星空行者','RA','R系',255040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('暗夜骑士','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('暴走音速','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('暴走马达','RA','R系',345600);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('曙光','RA','R系',78400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('未来骑士','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('末日','RA','R系',345600);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('极客','RA','R系',78400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('极速轨迹','RA','R系',288000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('梦幻之星','RA','R系',311040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('氪星之子','RA','R系',231040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('水瓶座','RA','R系',231040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('沙暴之子','RA','R系',231040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('沙漠魄影','RA','R系',159920);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('泡泡小子','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('流云','RA','R系',159920);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('流火战魂','RA','R系',96000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('涡轮','RA','R系',78400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('漂移之翼','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('潜行幻影','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('火力战神','RA','R系',311040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('火狐','RA','R系',480000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('火箭骑士','RA','R系',78400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('灵焰之风','RA','R系',120000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('烈枫','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('烈焰风暴','RA','R系',78400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('烈焰骑士','RA','R系',96000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('烈风','RA','R系',311040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('烽火','RA','R系',159920);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('焚天火','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('焰火孤星','RA','R系',231040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('熔岩','RA','R系',78400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('熔岩骑士','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('狂徒','RA','R系',159920);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('狂暴飞驰','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('狂蝎','RA','R系',180000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('狂飙勇士','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('狮子座','RA','R系',231040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('玄武','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('玉兔','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('疾风影流','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('疾驰幻象','RA','R系',78400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('白羊座','RA','R系',231040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('盗火者','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('碧空行者','RA','R系',120000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('秋日','RA','R系',78400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('科尔维特','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('紫色玫瑰','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('终结先锋','RA','R系',96000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('胜利之星','RA','R系',78400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('苍炎','RA','R系',96000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('苍蓝飓风','RA','R系',78400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('苍龙光翼','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('萤火','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('蓝色旋风','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('蓝色脉冲','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('蓝血伯爵','RA','R系',293280);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('虎魄','RA','R系',343920);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('蜂巢','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('赤炎刀锋','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('赤霄','RA','R系',159920);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('迷幻猎豹','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('追击者','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('追月','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('追踪者','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('逆影','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('逐风','RA','R系',78400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('逐魂者','RA','R系',293280);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('金牛座','RA','R系',231040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('铁血英豪','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('闪灵','RA','R系',97600);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('闪耀利箭','RA','R系',78400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('阳炎','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('雪原行者','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('雷电','RA','R系',102400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('雷鸣风暴','RA','R系',293280);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('霹雳轨迹','RA','R系',231040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('领航者','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('风之痕','RA','R系',151040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('风驰','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('飞瀑','RA','R系',151040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('飞翼','RA','R系',96000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('骇客','RA','R系',231040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('魅影','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('鸡','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('黄爵','RA','R系',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('龙魂','RA','R系',103040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('J计划','S','普通',375920);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('七月流火','S','普通',239040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('业火','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('先驱者','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('冷炎','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('北境','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('单身贵族','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('同心共舞','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('地火','S','普通',135040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('天使幻影','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('天际','S','普通',231040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('天韵','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('幻影','S','普通',255040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('幽灵亲王','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('御风者','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('心跳回忆','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('恶魔之锋','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('拓荒之狼','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('春雷','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('暗影疾行','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('暴君','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('最强S车','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('月光','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('朱雀','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('极光','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('极地光速','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('梦游仙境','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('浮光掠影','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('浮光裂魂','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('海洋之心','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('清风','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('炫光海浪','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('烈火冰焰','S','普通',159920);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('烈焰战魂','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('狂鲨','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('监工','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('破空之刃','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('碧色幻想','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('碧蓝怒火','S','普通',215040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('秋之刃','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('科迈罗','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('紫焰洪流','S','普通',143920);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('紫罗兰','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('紫色星空','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('红色先锋','S','普通',231040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('绝影','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('绯炎使者','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('脉冲新星','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('蓝色彗星','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('蔚蓝律动','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('街头霸王','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('质子游侠','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('踏浪','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('逐日者','S','普通',231040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('逢考必过','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('金色闪电','S','普通',319920);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('钢铁壁垒','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('铁血战狼','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('银翼','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('银色弧光','S','普通',293280);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('陶洛斯','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('雪域霸主','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('雪狼','S','普通',240000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('雷瑟','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('雷神之怒','S','普通',439920);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('雷霆','S','普通',239040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('飞虎','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('魔灵','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('黄蜂','S','普通',0);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('冰璃','SS','普通',1279920);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('斗神','SS','普通',951040);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('暗香','SS','普通',1279920);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('焚风','SS','普通',1279920);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('绝影上尉','SS','普通',768000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('黄龙','SS','普通',1279920);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('命运刀锋','T','T系',24000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('堕天使','T','T系',48000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('寒冰魔兽','T','T系',64000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('怒火狮王','T','T系',48000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('擎空','T','T系',16000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('无限之刃','T','T系',24000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('星云战神','T','T系',72000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('炽焰神凰','T','T系',64000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('猎空','T','T系',32000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('突击尖兵','T','T系',48000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('虎风毒影','T','T系',48000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('黄道守护神','T','T系',64000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('齐天大圣','T','T系',48000);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('双面旋风','火力','火力',158400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('天音鼓动','火力','火力',158400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('电光战神','火力','火力',134400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('离子冲锋','火力','火力',158400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('致命急速','火力','火力',158400);
INSERT INTO `car` (`Brand`,`Model`,`Type`,`Price`) VALUES ('铁爪屠夫','火力','火力',182400);
-- ----------------------------
-- Table structure for consumer
-- ----------------------------
    
DROP TABLE IF EXISTS `consumer`;
      
CREATE TABLE `consumer` (
  `CustomerID` bigint(20) NOT NULL AUTO_INCREMENT,
  `Name` varchar(30) NOT NULL,
  `ID` char(18) DEFAULT NULL,
  `CustomerPhone` char(11) DEFAULT NULL,
  `Password` varchar(100) NOT NULL,
  PRIMARY KEY (`CustomerID`),
  UNIQUE KEY `consumer_Name_uindex` (`Name`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4;
      
INSERT INTO `consumer` (`CustomerID`,`Name`,`ID`,`CustomerPhone`,`Password`) VALUES (1,'铁钻1号','113020','130120','113020');
INSERT INTO `consumer` (`CustomerID`,`Name`,`ID`,`CustomerPhone`,`Password`) VALUES (2,'天才博士','213040','130240','213040');
INSERT INTO `consumer` (`CustomerID`,`Name`,`ID`,`CustomerPhone`,`Password`) VALUES (3,'女王','313040','130340','313040');
INSERT INTO `consumer` (`CustomerID`,`Name`,`ID`,`CustomerPhone`,`Password`) VALUES (4,'夏日少女','413040','130440','413040');
INSERT INTO `consumer` (`CustomerID`,`Name`,`ID`,`CustomerPhone`,`Password`) VALUES (5,'邪·雷诺','513040','130540','513040');
INSERT INTO `consumer` (`CustomerID`,`Name`,`ID`,`CustomerPhone`,`Password`) VALUES (6,'闭月','613040','130640','613040');
-- ----------------------------
-- Table structure for worker
-- ----------------------------

DROP TABLE IF EXISTS `worker`;
      
CREATE TABLE `worker` (
  `WorkerID` bigint(20) NOT NULL AUTO_INCREMENT,
  `Name` varchar(30) NOT NULL,
  `WorkIDCard` char(18) NOT NULL,
  `WorkPhone` char(11) DEFAULT NULL,
  `WorkAge` tinyint(3) unsigned DEFAULT NULL,
  `Experience` bigint(20) NOT NULL DEFAULT '0',
  `Statement` enum('维修中','空闲中') DEFAULT '空闲中',
  `Password` varchar(100) NOT NULL,
  PRIMARY KEY (`WorkerID`),
  UNIQUE KEY `Worker_WorkIDCard_uindex` (`WorkIDCard`)
) ENGINE=InnoDB AUTO_INCREMENT=1000010010 DEFAULT CHARSET=utf8mb4;
      
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (1,'白勇太','1450','1450',0,45,'空闲中','1450');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (2,'凯奇','260800','260800',6,800,'空闲中','260800');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (3,'Birdy K','3752000','3752000',7,2000,'空闲中','3752000');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (4,'小橘子','4100488888','1004488888',10,6111,'空闲中','4100488888');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (5,'暗影橘子','51201500','12051500',12,1500,'空闲中','51201500');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (6,'千月','61201500','12061500',12,1500,'空闲中','61201500');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (7,'李斯特','71202500','12072500',12,2500,'空闲中','71202500');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (8,'凯瑟琳','81251500','12581500',12,1500,'空闲中','81251500');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (9,'甜美美','91256666','12596666',12,6666,'空闲中','91256666');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (10,'黄金橘子','101305888','130105888',13,5888,'空闲中','101305888');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (11,'亚瑟','111251999','125111999',12,1999,'空闲中','111251999');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (12,'艾米丽','121255888','125125888',12,5888,'空闲中','121255888');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (13,'忆星','131206666','130136666',13,6666,'空闲中','131306666');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (14,'特工Jay','141303199','130143199',13,3199,'空闲中','141303199');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (15,'小S','151306888','130156888',13,6888,'空闲中','151306888');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (16,'保罗','161302199','130162199',13,2199,'空闲中','161302199');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (17,'冰雪安娜','171307999','130177999',13,7999,'空闲中','171307999');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (18,'小蜜桃','181301599','130187599',13,7599,'空闲中','181307599');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (19,'白金橘子','19130269920','13019269920',13,2699,'空闲中','19130269920');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (20,'小禧','20130259920','13020259920',13,2599,'空闲中','20130259920');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (21,'雷诺','21130499940','13021499940',13,4999,'空闲中','21130499940');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (22,'艾薇','22130666640','13022666640',13,6666,'空闲中','22130666640');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (23,'疾风白勇太','23130279920','13023279920',13,2799,'空闲中','23130279920');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (24,'洛玉','24130769940','13024769940',13,7699,'空闲中','24130769940');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (25,'时空橘子','25130279920','13025279920',13,2799,'空闲中','25130279920');
INSERT INTO `worker` (`WorkerID`,`Name`,`WorkIDCard`,`WorkPhone`,`WorkAge`,`Experience`,`Statement`,`Password`) VALUES (26,'凛冬保罗','26130259920','13026259920',13,2599,'空闲中','26130259920');
-- ----------------------------
-- Table structure for order
-- ----------------------------

DROP TABLE IF EXISTS `order`;

CREATE TABLE `order` (
  `OrderID` bigint(20) NOT NULL,
  `LDate` datetime NOT NULL,
  `EDate` datetime DEFAULT NULL,
  `CarID` char(8) NOT NULL,
  `Brand` varchar(30) NOT NULL,
  `Model` varchar(30) NOT NULL,
  `CustomerID` bigint(20) NOT NULL,
  `Description` longtext,
  `WorkerID` bigint(20) DEFAULT NULL,
  `Pay` decimal(19,2) DEFAULT '1000.00',
  PRIMARY KEY (`OrderID`),
  KEY `car_consumer_CustomerID_fk` (`CustomerID`),
  KEY `order_car_Model_Brand_fk` (`Model`,`Brand`),
  KEY `order_worker_WorkerID_fk` (`WorkerID`),
  CONSTRAINT `car_consumer_CustomerID_fk` FOREIGN KEY (`CustomerID`) REFERENCES `consumer` (`CustomerID`),
  CONSTRAINT `order_car_Model_Brand_fk` FOREIGN KEY (`Model`, `Brand`) REFERENCES `car` (`Model`, `Brand`),
  CONSTRAINT `order_worker_WorkerID_fk` FOREIGN KEY (`WorkerID`) REFERENCES `worker` (`WorkerID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

INSERT INTO `order` (`OrderID`,`LDate`,`EDate`,`CarID`,`Brand`,`Model`,`CustomerID`,`WorkerID`,`Pay`) VALUES ('201001010000000001','2010-01-01 00:00:00','2020-07-11 12:02:26','15','威酷','C',1,1,'400.00');
INSERT INTO `order` (`OrderID`,`LDate`,`EDate`,`CarID`,`Brand`,`Model`,`CustomerID`,`WorkerID`,`Pay`) VALUES ('201012312359590001','2010-12-31 23:59:59','2011-01-01 00:00:00','525','暗夜骑士','RA',2,2,'2000.00');
INSERT INTO `order` (`OrderID`,`LDate`,`EDate`,`CarID`,`Brand`,`Model`,`CustomerID`,`WorkerID`,`Pay`) VALUES ('201101010000000001','2011-01-01 00:00:00','2011-12-31 23:59:59','1150','擎空','T',3,3,'4000.00');
INSERT INTO `order` (`OrderID`,`LDate`,`EDate`,`CarID`,`Brand`,`Model`,`CustomerID`,`WorkerID`,`Pay`) VALUES ('201112312359590001','2011-12-31 23:59:59','2012-01-01 00:00:00','23100','极速轨迹','RA',4,4,'8000.00');
INSERT INTO `order` (`OrderID`,`LDate`,`EDate`,`CarID`,`Brand`,`Model`,`CustomerID`,`WorkerID`,`Pay`) VALUES ('201201010000000001','2012-01-01 00:00:00','2012-12-31 23:59:59','36150','光电游侠','RA',5,5,'12000.00');
INSERT INTO `order` (`OrderID`,`LDate`,`EDate`,`CarID`,`Brand`,`Model`,`CustomerID`,`WorkerID`,`Pay`) VALUES ('201212312359590001','2012-12-31 23:59:59','2013-01-01 00:00:00','65250','金色闪电','S',6,6,'20000.00');
INSERT INTO `order` (`OrderID`,`LDate`,`EDate`,`CarID`,`Brand`,`Model`,`CustomerID`,`WorkerID`,`Pay`) VALUES ('201301010000000001','2013-01-01 00:00:00','2013-12-31 23:59:59','10800','七月流火','S',1,7,'800.00');
INSERT INTO `order` (`OrderID`,`LDate`,`EDate`,`CarID`,`Brand`,`Model`,`CustomerID`,`WorkerID`,`Pay`) VALUES ('201312312359590001','2013-12-31 23:59:59','2014-01-01 00:00:00','50450','X-战车','RA',2,8,'4500.00');
INSERT INTO `order` (`OrderID`,`LDate`,`EDate`,`CarID`,`Brand`,`Model`,`CustomerID`,`WorkerID`,`Pay`) VALUES ('201401010000000001','2014-01-01 00:00:00','2014-12-31 23:59:59','10010','银色弧光','S',3,9,'10000.00');
INSERT INTO `order` (`OrderID`,`LDate`,`EDate`,`CarID`,`Brand`,`Model`,`CustomerID`,`WorkerID`,`Pay`) VALUES ('201412312359590001','2014-12-31 23:59:59','2015-01-01 00:00:00','50060','火狐','RA',4,10,'60000.00');
INSERT INTO `order` (`OrderID`,`LDate`,`EDate`,`CarID`,`Brand`,`Model`,`CustomerID`,`WorkerID`,`Pay`) VALUES ('201501010000000001','2015-01-01 00:00:00','2015-12-31 23:59:59','10001','斗神','SS',5,11,'130000.00');
INSERT INTO `order` (`OrderID`,`LDate`,`EDate`,`CarID`,`Brand`,`Model`,`CustomerID`,`WorkerID`,`Pay`) VALUES ('201512312359590001','2015-12-31 23:59:59','2016-01-01 00:00:00','20003','冰璃','SS',6,12,'300000.00');
INSERT INTO `order` (`OrderID`,`LDate`,`EDate`,`CarID`,`Brand`,`Model`,`CustomerID`,`WorkerID`,`Pay`) VALUES ('201612312359590001','2016-12-31 23:59:59','2017-01-01 00:00:00','30063','暴走马达','RA',2,14,'24000.00');
INSERT INTO `order` (`OrderID`,`LDate`,`EDate`,`CarID`,`Brand`,`Model`,`CustomerID`,`WorkerID`,`Pay`) VALUES ('201701010000000001','2017-01-01 00:00:00','2017-12-31 23:59:59','11050','雷神之怒','S',3,15,'40000.00');