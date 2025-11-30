#include "s_gamemain.h"
#include "SceneGameStage1.h"
#include "framedata.h"
#include "motiondata.h"

struct CHARA_MOTION tblMotion[] = {
	// MOTION_x_xxxx ÇÃèáî‘Ç…ÉfÅ[É^Çï¿Ç◊ÇÈ
	{	// MOTION_R_STAND			0
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1048, 6, 0,0 },
			{ 1049, 6, 0,0 },
			{ 1050, 6, 0,0 },
			{ 1051, 6, 0,0 },
			{ 1052, 6, 0,0 },
			{ 1053, 6, 0,0 },
			{ 1054, 6, 0,0 },
			{ 1055, 6, 0,0 },
			{ 1056, 6, 0,0 },
			{ 1057, 6, 0,0 },
			{ 1058, 6, 0,0 },
			{ 1059, 6, 0,0 },
			{ 1060, 6, 0,0 },
			{ 1061, 6, 0,0 },
			{ 1062, 6, 0,0 },
			{ 1063, 6, 0,0 },
			{ 1064, 6, 0,0 },
			{ 1065, 6, 0,0 },
			{ 1066, 6, 0,0 },
			{ 1067, 6, 0,0 },
			{ 1068, 6, 0,0 },
			{ 1069, 6, 0,0 },
			{ 1070, 6, 0,0 },
			{ 1071, 6, 0,0 },
			{ 1072, 6, 0,0 },
			{ 1073, 6, 0,0 },
			{ 1074, 6, 0,0 },
			{ 1075, 6, 0,0 },
			{ 1076, 6, 0,0 },
			{ 1077, 6, 0,0 },
			{ 1078, 6, 0,0 },
			{ 1079, 6, 0,0 },
			{ 1080, 6, 0,0 },
			{ 1081, 6, 0,0 },
			{ 1082, 6, 0,0 },
			{ 1083, 6, 0,0 },
			{ 1084, 6, 0,0 },
			{ 1085, 6, 0,0 },
			{ 1086, 6, 0,0 },
			{ 1087, 6, 0,0 },
			{ 1088, 6, 0,0 },
			{ 1089, 6, 0,0 },
			{ 1090, 6, 0,0 },
			{ 1091, 6, 0,0 },
			{ 1092, 6, 0,0 },
			{ 1093, 6, 0,0 },
			{ 1094, 6, 0,0 },
			{ 1095, 6, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	// MOTION_L_STAND			1
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1000, 6, 0,0 },
			{ 1001, 6, 0,0 },
			{ 1002, 6, 0,0 },
			{ 1003, 6, 0,0 },
			{ 1004, 6, 0,0 },
			{ 1005, 6, 0,0 },
			{ 1006, 6, 0,0 },
			{ 1007, 6, 0,0 },
			{ 1008, 6, 0,0 },
			{ 1009, 6, 0,0 },
			{ 1010, 6, 0,0 },
			{ 1011, 6, 0,0 },
			{ 1012, 6, 0,0 },
			{ 1013, 6, 0,0 },
			{ 1014, 6, 0,0 },
			{ 1015, 6, 0,0 },
			{ 1016, 6, 0,0 },
			{ 1017, 6, 0,0 },
			{ 1018, 6, 0,0 },
			{ 1019, 6, 0,0 },
			{ 1020, 6, 0,0 },
			{ 1021, 6, 0,0 },
			{ 1022, 6, 0,0 },
			{ 1023, 6, 0,0 },
			{ 1024, 6, 0,0 },
			{ 1025, 6, 0,0 },
			{ 1026, 6, 0,0 },
			{ 1027, 6, 0,0 },
			{ 1028, 6, 0,0 },
			{ 1029, 6, 0,0 },
			{ 1030, 6, 0,0 },
			{ 1031, 6, 0,0 },
			{ 1032, 6, 0,0 },
			{ 1033, 6, 0,0 },
			{ 1034, 6, 0,0 },
			{ 1035, 6, 0,0 },
			{ 1036, 6, 0,0 },
			{ 1037, 6, 0,0 },
			{ 1038, 6, 0,0 },
			{ 1039, 6, 0,0 },
			{ 1040, 6, 0,0 },
			{ 1041, 6, 0,0 },
			{ 1042, 6, 0,0 },
			{ 1043, 6, 0,0 },
			{ 1044, 6, 0,0 },
			{ 1045, 6, 0,0 },
			{ 1046, 6, 0,0 },
			{ 1047, 6, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	// MOTION_R_RUN			2
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1108, 6, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_WALK+2 },
			{ 1109, 6, 0,0 },
			{ 1110, 6, 0,0 },
			{ 1111, 6, 0,0 },
			{ 1112, 6, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_WALK + 4 },
			{ 1113, 6, 0,0 },
			{ 1114, 6, 0,0 },
			{ 1115, 6, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	// MOTION_L_RUN			3
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1100, 6, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_WALK+4 },
			{ 1101, 6, 0,0 },
			{ 1102, 6, 0,0 },
			{ 1103, 6, 0,0 },
			{ 1104, 6, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_WALK + 2 },
			{ 1105, 6, 0,0 },
			{ 1106, 6, 0,0 },
			{ 1107, 6, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},

	{	// MOTION_R_WALK			4
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1216, 6, 0,0 },
			{ 1217, 6, 0,0 },
			{ 1218, 6, 0,0 },
			{ 1219, 6, 0,0 },
			{ 1220, 6, 0,0 },
			{ 1221, 6, 0,0 },
			{ 1222, 6, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_WALK + 1},
			{ 1223, 6, 0,0 },
			{ 1224, 6, 0,0 },
			{ 1225, 6, 0,0 },
			{ 1226, 6, 0,0 },
			{ 1227, 6, 0,0 },
			{ 1228, 6, 0,0 },
			{ 1229, 6, 0,0 },
			{ 1230, 6, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_WALK + 3},
			{ 1231, 6, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},

	{	// MOTION_L_WALK			5
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1200, 6, 0,0 },
			{ 1201, 6, 0,0 },
			{ 1202, 6, 0,0 },
			{ 1203, 6, 0,0 },
			{ 1204, 6, 0,0 },
			{ 1205, 6, 0,0 },
			{ 1206, 6, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_WALK + 3},
			{ 1207, 6, 0,0 },
			{ 1208, 6, 0,0 },
			{ 1209, 6, 0,0 },
			{ 1210, 6, 0,0 },
			{ 1211, 6, 0,0 },
			{ 1212, 6, 0,0 },
			{ 1213, 6, 0,0 },		
			{ 1214, 6, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_WALK + 1},
			{ 1215, 6, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	
	{	// MOTION_R_DAMAGE			6
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1308, 6, -10,0 },
			{ 1309, 6, -6,0 },
			{ 1310, 6, -4,0 },
			{ 1311, 6, 0,0 },
			{ 1312, 6, 0,0 },
			{ 1313, 6, 0,0 },
			{ 1314, 6, 0,0 },
			{ 1315, 6, 0,0 },
			{ CHARA_MOTION_CMD_HPCHECK, 0},
			{ CHARA_MOTION_CMD_MOTION, MOTION_R_STAND },
		},
	},
	{	// MOTION_L_DAMAGE			7
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1300, 6, 10,0 },
			{ 1301, 6, 6,0 },
			{ 1302, 6, 4,0 },
			{ 1303, 6, 0,0 },
			{ 1304, 6, 0,0 },
			{ 1305, 6, 0,0 },
			{ 1306, 6, 0,0 },
			{ 1307, 6, 0,0 },
			{ CHARA_MOTION_CMD_HPCHECK, 0},
			{ CHARA_MOTION_CMD_MOTION, MOTION_L_STAND },
		},
	},
	
	{	//	MOTION_SQUAT_R			8
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1408, 6, 0,50 },
			{ 1409, 6, 0,50 },
			{ 1410, 6, 0,50 },
			{ 1411, 6, 0,50 },
			{ 1412, 6, 0,50 },
			{ 1413, 6, 0,50 },
			{ 1414, 6, 0,50 },
			{ 1415, 6, 0,50 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_R_LIEDOWN  },
		},
	},
	{	//	MOTION_SQUAT_L			9
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1400, 6, 0,50 },
			{ 1401, 6, 0,50 },
			{ 1402, 6, 0,50 },
			{ 1403, 6, 0,50 },
			{ 1404, 6, 0,50 },
			{ 1405, 6, 0,50 },
			{ 1406, 6, 0,50 },
			{ 1407, 6, 0,50 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_L_LIEDOWN },
		},
	},
	{	//	MOTION_L_LIEDOWN			10
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1415, 24, 0,50 },
			{ CHARA_MOTION_CMD_LOOP, 0  },
		},
	},
	{	//	MOTION_R_LIEDOWN			11
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1407, 24, 0,50 },
			{ CHARA_MOTION_CMD_LOOP, 0  },
		},
	},


	{	//	MOTION_L_GETUP			12
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1508, 6, 0,50 },
			{ 1509, 6, 0,50 },
			{ 1510, 6, 0,50 },
			{ 1511, 6, 0,50 },
			{ 1512, 6, 0,50 },
			{ 1513, 6, 0,50 },
			{ 1514, 6, 0,50 },
			{ 1515, 6, 0,50 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_R_STAND  },
		},
	},
	{	//	MOTION_R_GETUP			13
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1500, 6, 0,50 },
			{ 1501, 6, 0,50 },
			{ 1502, 6, 0,50 },
			{ 1503, 6, 0,50 },
			{ 1504, 6, 0,50 },
			{ 1505, 6, 0,50 },
			{ 1506, 6, 0,50 },
			{ 1507, 6, 0,50 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_L_STAND },
		},
	},

	{	//	MOTION_R_THROW			14
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1608, 6, 0,0 },
			{ 1609, 6, 0,0 },
			{ 1610, 6, 0,0 },
			{ CHARA_MOTION_CMD_FIRE, 0,},
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_THROW},
			{ 1611, 6, 0,0 },
			{ 1612, 6, 0,0 },
			{ 1613, 6, 0,0 },
			{ 1614, 6, 0,0 },
			{ 1615, 6, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_R_STAND  },
		},
	},
	{	//	MOTION_L_THROW			15
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1600, 6, 0,0 },
			{ 1601, 6, 0,0 },
			{ 1602, 6, 0,0 },
			{ CHARA_MOTION_CMD_FIRE, 0,},
			{ CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_THROW},
			{ 1603, 6, 0,0 },
			{ 1604, 6, 0,0 },
			{ 1605, 6, 0,0 },
			{ 1606, 6, 0,0 },
			{ 1607, 6, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_L_STAND  },
		},
	},

	{	//	MOTION_R_NO_THROW			16
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1708, 6, 0,0 },
			{ 1709, 6, 0,0 },
			{ 1710, 6, 0,0 },
			{ 1711, 6, 0,0 },
			{ 1712, 6, 0,0 },
			{ 1713, 6, 0,0 },
			{ 1714, 6, 0,0 },
			{ 1715, 6, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_R_STAND  },
		},
	},
	{	//	MOTION_L_NO_THROW			17
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1700, 6, 0,0 },
			{ 1701, 6, 0,0 },
			{ 1702, 6, 0,0 },
			{ 1703, 6, 0,0 },
			{ 1704, 6, 0,0 },
			{ 1705, 6, 0,0 },
			{ 1706, 6, 0,0 },
			{ 1707, 6, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_L_STAND  },
		},
	},

	{	//	MOTION_L_DEATH			18
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1816, 6, 0,0 },
			{ 1817, 6, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_DEAD},
			{ 1818, 6, 0,0 },
			{ 1819, 6, 0,0 },
			{ 1820, 6, 0,0 },
			{ 1821, 6, 0,0 },
			{ 1822, 6, 0,0 },
			{ 1823, 6, 0,0 },
			{ 1824, 6, 0,0 },
			{ 1825, 6, 0,0 },
			{ 1826, 6, 0,0 },
			{ 1827, 6, 0,0 },
			{ 1828, 6, 0,0 },
			{ 1829, 6, 0,0 },
			{ 1830, 6, 0,0 },
			{ 1831, 6, 0,0 },
			{ CHARA_MOTION_CMD_END , 0  },
			{ CHARA_MOTION_CMD_LOOP, 0  },
		},
	},

	{	//	MOTION_R_DEATH			19
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1800, 6, 0,0 },
			{ 1801, 6, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_DEAD},
			{ 1802, 6, 0,0 },
			{ 1803, 6, 0,0 },
			{ 1804, 6, 0,0 },
			{ 1805, 6, 0,0 },
			{ 1806, 6, 0,0 },
			{ 1807, 6, 0,0 },
			{ 1808, 6, 0,0 },
			{ 1809, 6, 0,0 },
			{ 1810, 6, 0,0 },
			{ 1811, 6, 0,0 },
			{ 1812, 6, 0,0 },
			{ 1813, 6, 0,0 },
			{ 1814, 6, 0,0 },
			{ 1815, 6, 0,0 },
			{ CHARA_MOTION_CMD_END , 0  },
			{ CHARA_MOTION_CMD_LOOP, 0  },
		},
	},

	{	//	MOTION_UNLOCK			20
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1900, 8, 0,0 },
			{ 1901, 8, 0,0 },
			{ 1902, 8, 0,0 },
			{ 1903, 8, 0,0 },
			{ 1904, 8, 0,0 },
			{ 1905, 8, 0,0 },
			{ 1906, 8, 0,0 },
			{ 1907, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0  },
		},
	},

	{	//MOTION_STAIR_DOWN_BACK			21
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			
			{ 2000, 6, 0,6 },			//y+=45 x+=100
			{ CHARA_MOTION_CMD_LAYER, 0  },
			{ 2001, 6, 0,7 },
			{ 2002, 6, 0,7 },
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_STAIR },
			{ 2003, 6, 0,7 },
			{ 2004, 6, 0,7 },
			{ 2005, 6, 0,7 },
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_STAIR },
			{ 2006, 6, 0,7 },
			{ 2007, 6, 0,7 },
			{ 2039, 8, -7,0 },
			{ 2040, 8, -7,0 },
			{ 2041, 8, -7,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_STAIR },
			{ 2042, 8, -7,0 },
			{ 2043, 8, -7,0 },
			{ 2044, 8, -7,0 },
			{ 2045, 8, -7,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_STAIR_DOWN_FRONT  },
		},
	},

	{	//MOTION_STAIR_DOWN_FRONT			22
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 2008, 8, 0,7 },
			{ CHARA_MOTION_CMD_LAYER, 0  },
			{ 2009, 8, 0,7 },
			{ 2010, 8, 0,7 },
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_STAIR },
			{ 2011, 8, 0,7 },
			{ 2012, 8, 0,7 },
			{ 2013, 8, 0,7 },
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_STAIR },
			{ 2014, 8, 0,7 },
			{ 2015, 8, 0,6 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_L_STAND },
		},
	},

	{	//MOTION_STAIR_UP_BACK			23
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 2016, 8, 0,-7 },
			{ 2017, 8, 0,-7 },
			{ 2018, 8, 0,-7 },
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_STAIR },
			{ 2019, 8, 0,-7 },
			{ 2020, 8, 0,-7 },
			{ 2021, 8, 0,-6 },
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_STAIR },
			{ CHARA_MOTION_CMD_LAYER, 0  },
			{ 2022, 8, 0,-6 },
			{ 2023, 8, 0,-6 },
			{ 2032, 8, 7,0 },
			{ 2033, 8, 7,0 },
			{ 2034, 8, 7,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_STAIR },
			{ 2035, 8, 7,0 },
			{ 2036, 8, 7,0 },
			{ 2037, 8, 7,0 },
			{ 2038, 8, 7,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_STAIR_UP_FRONT},
		},
	},

	{	//MOTION_STAIR_UP_FRONT			24
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			
			{ 2024, 8, 0, -6 },
			{ 2025, 8, 0, -6 },
			{ 2026, 8, 0, -6 },
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_STAIR },
			{ 2027, 8, 0, -6 },
			{ 2028, 8, 0, -6 },
			{ 2029, 8, 0, -6 },
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_STAIR },
			{ 2030, 8, 0, -6 },
			{ 2031, 8, 0, -6 },
			{ CHARA_MOTION_CMD_LAYER, 0  },
			//{ CHARA_MOTION_CMD_GRAVITY, 0  },
			{ CHARA_MOTION_CMD_MOTION, MOTION_R_STAND},

		},
	},

	{	//MOTION_START_STAIR		25
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,

			{ 2100, 8, 0, 7 },
			{ 2101, 8, 0, 7 },
			{ 2102, 8, 0, 7 },
			{ 2103, 8, 0, 7 },
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_WALK },
			{ 2104, 8, 0, 7 },
			{ 2105, 8, 0, 7 },
			{ 2106, 8, 0, 7 },
			{CHARA_MOTION_CMD_PLAYSE,SE_PLAYER_WALK },
			{ 2107, 8, 0, 7 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_R_STAND},

		},
	},

	{	// MOTION_ITEM_POINT_0_NORMAL			26
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 10000, 8, 0,0 },
			{ 10001, 8, 0,0 },
			{ 10002, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	// MOTION_ITEM_POINT_1_NORMAL			27
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 10010, 8, 0,0 },
			{ 10011, 8, 0,0 },
			{ 10012, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	// MOTION_ITEM_POINT_2_NORMAL		28
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 10020, 8, 0,0 },
			{ 10021, 8, 0,0 },
			{ 10022, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	// MOTION_ITEM_POINT_3_NORMAL		29
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 10030, 8, 0,0 },
			{ 10031, 8, 0,0 },
			{ 10032, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	// MOTION_ITEM_POINT_4_NORMAL		30
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 10040, 8, 0,0 },
			{ 10040, 8, 0,0 },
			{ 10040, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	// ìG1
	{	//	MOTION_ENEMY1_R_RUN				31
		1,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20000, 8, 0,0 },
			{ 20001, 8, 0,0 },
			{ 20002, 8, 0,0 },
			{ 20003, 8, 0,0 },
			{ 20004, 8, 0,0 },
			{ 20005, 8, 0,0 },
			{ 20006, 8, 0,0 },
			{ 20007, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	//	MOTION_ENEMY1_L_RUN				32
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20000, 8, 0,0 },
			{ 20001, 8, 0,0 },
			{ 20002, 8, 0,0 },
			{ 20003, 8, 0,0 },
			{ 20004, 8, 0,0 },
			{ 20005, 8, 0,0 },
			{ 20006, 8, 0,0 },
			{ 20007, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	// MOTION_ENEMY1_R_DAMAGE			33
		1,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20010, 4, -20,0 },
			{ 20010, 4, -12,0 },
			{ 20010, 4, -8,0 },
			{ 20010, 4, 0,0 },
			{ CHARA_MOTION_CMD_HPCHECK, 0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY1_R_RUN },
		},
	},
	{	// MOTION_ENEMY1_L_DAMAGE			34
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20010, 4, 20,0 },
			{ 20010, 4, 12,0 },
			{ 20010, 4, 8,0 },
			{ 20010, 4, 0,0 },
			{ CHARA_MOTION_CMD_HPCHECK, 0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY1_L_RUN },
		},
	},
	{	//	MOTION_ENEMY1_R_ATTACK			35
		1,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20020, 8, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY1_ATTACK },
			{ 20021, 8, 0,0 },
			{ 20022, 8, 0,0 },
			{ 20023, 8, 0,0 },
			{ 20024, 8, 0,0 },
			{ 20025, 8, 0,0 },
			{ 20026, 8, 0,0 },
			{ 20027, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	//	MOTION_ENEMY1_L_ATTACK			36
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20020, 8, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY1_ATTACK },
			{ 20021, 8, 0,0 },
			{ 20022, 8, 0,0 },
			{ 20023, 8, 0,0 },
			{ 20024, 8, 0,0 },
			{ 20025, 8, 0,0 },
			{ 20026, 8, 0,0 },
			{ 20027, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	//	MOTION_ENEMY1_R_TURN			37
		1,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20030, 4, 0,0 },
			{ 20031, 4, 0,0 },
			{ 20032, 4, 0,0 },
			{ 20033, 4, 0,0 },
			{ 20034, 4, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY1_L_RUN },
		},
	},
	{	//	MOTION_ENEMY1_R_TURN			38
		1,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20035, 4, 0,0 },
			{ 20036, 4, 0,0 },
			{ 20037, 4, 0,0 },
			{ 20038, 4, 0,0 },
			{ 20039, 4, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY1_R_RUN },
		},
	},
	
	// ìG2
	{	//	MOTION_ENEMY2_R_RUN			39
		1,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20100, 8, 0,0 },		
			{ 20101, 8, 0,0 },
			{ 20102, 8, 0,0 },
			{ 20103, 8, 0,0 },
			{ 20104, 8, 0,0 },
			{ 20105, 8, 0,0 },
			{ 20106, 8, 0,0 },
			{ 20107, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	//	MOTION_ENEMY2_L_RUN			40
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20100, 8, 0,0 },		
			{ 20101, 8, 0,0 },
			{ 20102, 8, 0,0 },
			{ 20103, 8, 0,0 },
			{ 20104, 8, 0,0 },
			{ 20105, 8, 0,0 },
			{ 20106, 8, 0,0 },
			{ 20107, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	// MOTION_ENEMY2_R_DAMAGE			41
		1,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20110, 10, -4,0 },
			{ 20111, 10, -4,0 },
			{ 20112, 10, -4,0 },
			{ 20113, 10, -4,0 },
			{ 20114, 10, 0,0 },
			{ 20115, 10, 0,0 },
			{ 20116, 10, 0,0 },
			{ 20117, 10, 0,0 },
			//{ CHARA_MOTION_CMD_GRAVITY, 0 },
			{ CHARA_MOTION_CMD_HPCHECK, 0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY2_R_RUN },
		},
	},
	{	// MOTION_ENEMY2_L_DAMAGE			42
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20110, 10, 4,0 },
			{ 20111, 10, 4,0 },
			{ 20112, 10, 4,0 },
			{ 20113, 10, 4,0 },
			{ 20114, 10, 0,0 },
			{ 20115, 10, 0,0 },
			{ 20116, 10, 0,0 },
			{ 20117, 10, 0,0 },
			//{ CHARA_MOTION_CMD_GRAVITY, 0 },
			{ CHARA_MOTION_CMD_HPCHECK, 0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY2_R_RUN },
		},
	},
	{	//	MOTION_ENEMY2_R_ATTACK			43
		1,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20120, 8, 0,0 },	
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY2_ATTACK },
			{ 20121, 8, 0,0 },
			{ 20122, 8, 0,0 },
			{ 20123, 8, 0,0 },
			{ 20124, 8, 0,0 },
			{ 20125, 8, 0,0 },
			{ 20126, 8, 0,0 },
			{ 20127, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	//	MOTION_ENEMY2_L_ATTACK			44
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20120, 8, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY2_ATTACK },
			{ 20121, 8, 0,0 },
			{ 20122, 8, 0,0 },
			{ 20123, 8, 0,0 },
			{ 20124, 8, 0,0 },
			{ 20125, 8, 0,0 },
			{ 20126, 8, 0,0 },
			{ 20127, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	//	MOTION_ENEMY2_R_TURN			45
		1,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20130, 4, 0,0 },
			{ 20131, 4, 0,0 },
			{ 20132, 4, 0,0 },
			{ 20133, 4, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY2_L_RUN },
		},
	},
	{	//	MOTION_ENEMY2_L_TURN			46
		1,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20135, 4, 0,0 },
			{ 20136, 4, 0,0 },
			{ 20137, 4, 0,0 },
			{ 20138, 4, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY2_R_RUN },
		},
	},

	{	//	MOTION_ENEMY2_R_DEATH			
		1,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20140, 4, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0  },
		},
	},
	{	//	MOTION_ENEMY2_L_DEATH			
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20140, 4, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0  },
		},
	},

	{	//	MOTION_ENEMY_CHANGE_ZOMBIE				47
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20150, 8, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY2_TO_ZOMBIE },
			{ 20151, 8, 0,0 },
			{ 20152, 8, 0,0 },
			{ 20153, 8, 0,0 },
			{ 20154, 8, 0,0 },
			{ 20155, 8, 0,0 },
			{ 20156, 8, 0,0 },
			{ 20150, 8, 0,0 },
			{ 20151, 8, 0,0 },
			{ 20152, 8, 0,0 },
			{ 20153, 8, 0,0 },
			{ 20154, 8, 0,0 },
			{ 20155, 8, 0,0 },
			{ 20156, 8, 0,0 },
			{ 20150, 8, 0,0 },
			{ 20151, 8, 0,0 },
			{ 20152, 8, 0,0 },
			{ 20153, 8, 0,0 },
			{ 20154, 8, 0,0 },
			{ 20155, 8, 0,0 },
			{ 20156, 8, 0,0 },
			{ 20150, 8, 0,0 },
			{ 20151, 8, 0,0 },
			{ 20152, 8, 0,0 },
			{ 20153, 8, 0,0 },
			{ 20154, 8, 0,0 },
			{ 20155, 8, 0,0 },
			{ 20156, 8, 0,0 },
			{ 20150, 8, 0,0 },
			{ 20151, 8, 0,0 },
			{ 20152, 8, 0,0 },
			{ 20153, 8, 0,0 },
			{ 20154, 8, 0,0 },
			{ 20155, 8, 0,0 },
			{ 20156, 8, 0,0 },
			{ 20150, 8, 0,0 },
			{ 20151, 8, 0,0 },
			{ 20152, 8, 0,0 },
			{ 20153, 8, 0,0 },
			{ 20154, 8, 0,0 },
			{ 20155, 8, 0,0 },
			{ 20156, 8, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, CHARA_MOTION_CMD_CHANGE },
		},
	},

	// ìG3
	{	//	MOTION_ENEMY3_R_RUN				47
		1,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20200, 8, 0,0 },
			{ 20201, 8, 0,0 },
			{ 20202, 8, 0,0 },
			{ 20203, 8, 0,0 },
			{ 20204, 8, 0,0 },
			{ 20205, 8, 0,0 },
			{ 20206, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	//	MOTION_ENEMY3_L_RUN				48
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20200, 8, 0,0 },
			{ 20201, 8, 0,0 },
			{ 20202, 8, 0,0 },
			{ 20203, 8, 0,0 },
			{ 20204, 8, 0,0 },
			{ 20205, 8, 0,0 },
			{ 20206, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	// MOTION_ENEMY3_R_DAMAGE			49
		1,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20210, 8, 0,0 },
			{ 20211, 8, 0,0 },
			{ 20212, 6, 0,0 },
			{ 20213, 6, 0,0 },
			{ 20214, 6, 0,0 },
			{ 20215, 6, 0,0 },
			{ 20216, 6, 0,0 },
			{ CHARA_MOTION_CMD_HPCHECK, 0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY3_R_RUN },
		},
	},
	{	// MOTION_ENEMY3_L_DAMAGE			50
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20210, 8, 0,0 },
			{ 20211, 8, 0,0 },
			{ 20212, 6, 0,0 },
			{ 20213, 6, 0,0 },
			{ 20214, 6, 0,0 },
			{ 20215, 6, 0,0 },
			{ 20216, 6, 0,0 },
			{ CHARA_MOTION_CMD_HPCHECK, 0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY3_R_RUN },
		},
	},
	{	//	MOTION_ENEMY3_R_ATTACK			51
		1,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20220, 8, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY3_ATTACK },
			{ 20221, 8, 0,0 },
			{ 20222, 8, 0,0 },
			{ 20223, 8, 0,0 },
			{ 20224, 8, 0,0 },
			{ 20225, 8, 0,0 },
			{ 20226, 8, 0,0 },
			{ 20227, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	//	MOTION_ENEMY3_L_ATTACK			52
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20220, 8, 0,0 },	
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY3_ATTACK },
			{ 20221, 8, 0,0 },
			{ 20222, 8, 0,0 },
			{ 20223, 8, 0,0 },
			{ 20224, 8, 0,0 },
			{ 20225, 8, 0,0 },
			{ 20226, 8, 0,0 },
			{ 20227, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	//	MOTION_ENEMY3_R_TURN			53
		1,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20230, 4, 0,0 },
			{ 20231, 4, 0,0 },
			{ 20232, 4, 0,0 },
			{ 20233, 4, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY3_L_RUN },
		},
	},
	{	//	MOTION_ENEMY3_R_TURN			54
		1,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20235, 4, 0,0 },
			{ 20236, 4, 0,0 },
			{ 20237, 4, 0,0 },
			{ 20238, 4, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY3_R_RUN },
		},
	},

	// ìG4
	{	//	MOTION_ENEMY4_R_UNDISCOVER_RUN				55
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20316, 8, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_WALK + 0 },
			{ 20317, 8, 0,0 },
			{ 20318, 8, 0,0 },
			{ 20319, 8, 0,0 },
			{ 20320, 8, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_WALK + 2 },
			{ 20321, 8, 0,0 },
			{ 20322, 8, 0,0 },
			{ 20323, 8, 0,0 },
			{ 20324, 8, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_WALK + 1 },
			{ 20325, 8, 0,0 },
			{ 20326, 8, 0,0 },
			{ 20327, 8, 0,0 },
			{ 20328, 8, 0,0 },
			{ 20329, 8, 0,0 },
			{ 20330, 8, 0,0 },
			{ 20331, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	//	MOTION_ENEMY4_L_UNDISCOVER_RUN			56
		1,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20300, 8, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_WALK + 1 },
			{ 20301, 8, 0,0 },
			{ 20302, 8, 0,0 },
			{ 20303, 8, 0,0 },
			{ 20304, 8, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_WALK + 2 },
			{ 20305, 8, 0,0 },
			{ 20306, 8, 0,0 },
			{ 20307, 8, 0,0 },
			{ 20308, 8, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_WALK + 0 },
			{ 20309, 8, 0,0 },
			{ 20310, 8, 0,0 },
			{ 20311, 8, 0,0 },
			{ 20312, 8, 0,0 },
			{ 20313, 8, 0,0 },
			{ 20314, 8, 0,0 },
			{ 20315, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},

	// ìG4
	{	//	MOTION_ENEMY4_R_RUN				55
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20356, 8, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_WALK + 0 },
			{ 20357, 8, 0,0 },
			{ 20358, 8, 0,0 },
			{ 20359, 8, 0,0 },
			{ 20360, 8, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_WALK + 2 },
			{ 20361, 8, 0,0 },
			{ 20362, 8, 0,0 },
			{ 20363, 8, 0,0 },
			{ 20364, 8, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_WALK + 1 },
			{ 20365, 8, 0,0 },
			{ 20366, 8, 0,0 },
			{ 20367, 8, 0,0 },
			{ 20368, 8, 0,0 },
			{ 20369, 8, 0,0 },
			{ 20370, 8, 0,0 },
			{ 20371, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	//	MOTION_ENEMY4_L_RUN			56
		1,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20340, 8, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_WALK+1 },
			{ 20341, 8, 0,0 },
			{ 20342, 8, 0,0 },
			{ 20343, 8, 0,0 },
			{ 20344, 8, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_WALK + 2 },
			{ 20345, 8, 0,0 },
			{ 20346, 8, 0,0 },
			{ 20347, 8, 0,0 },
			{ 20348, 8, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_WALK+0 },
			{ 20349, 8, 0,0 },
			{ 20350, 8, 0,0 },
			{ 20351, 8, 0,0 },
			{ 20352, 8, 0,0 },
			{ 20353, 8, 0,0 },
			{ 20354, 8, 0,0 },
			{ 20355, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},

	{	// MOTION_ENEMY4_R_DAMAGE			57
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20388, 4, 0,0 },
			{ 20389, 4, 0,0 },
			{ 20390, 4, 0,0 },
			{ 20391, 4, 0,0 },
			{ 20392, 4, 0,0 },
			{ 20393, 4, 0,0 },
			{ 20394, 4, 0,0 },
			{ 20395, 4, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY4_R_STAN },
		},
	},
	{	// MOTION_ENEMY4_L_DAMAGE			58
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20380, 4, 0,0 },
			{ 20381, 4, 0,0 },
			{ 20382, 4, 0,0 },
			{ 20383, 4, 0,0 },
			{ 20384, 4, 0,0 },
			{ 20385, 4, 0,0 },
			{ 20386, 4, 0,0 },
			{ 20387, 4, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY4_L_STAN },
		},
	},

	{	//	MOTION_ENEMY4_R_ATTACK			59
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20416, 8, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_ATTACK},
			{ 20417, 8, 0,0 },
			{ 20418, 8, 0,0 },
			{ 20419, 8, 0,0 },
			{ 20420, 8, 0,0 },
			{ 20421, 6, 0,0 },
			{ 20422, 6, 0,0 },
			{ 20423, 6, 0,0 },
			{ 20424, 6, 0,0 },
			{ 20425, 6, 0,0 },
			{ 20426, 6, 0,0 },
			{ 20427, 6, 0,0 },
			{ 20428, 6, 0,0 },
			{ 20429, 6, 0,0 },
			{ 20430, 6, 0,0 },
			{ 20431, 6, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY4_R_RUN },
		},
	},

	{	//	MOTION_ENEMY4_L_ATTACK			60
		1,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20400, 8, 0,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_ATTACK},
			{ 20401, 8, 0,0 },
			{ 20402, 8, 0,0 },
			{ 20403, 8, 0,0 },
			{ 20404, 8, 0,0 },
			{ 20405, 6, 0,0 },
			{ 20406, 6, 0,0 },
			{ 20407, 6, 0,0 },
			{ 20408, 6, 0,0 },
			{ 20409, 6, 0,0 },
			{ 20410, 6, 0,0 },
			{ 20411, 6, 0,0 },
			{ 20412, 6, 0,0 },
			{ 20413, 6, 0,0 },
			{ 20414, 6, 0,0 },
			{ 20415, 6, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY4_L_RUN },
		},
	},

	{	//	MOTION_ENEMY4_R_THROW			61
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20456, 8, 0,0 },
			{ 20457, 8, 0,0 },
			{ 20458, 8, 0,0 },
			{ 20459, 8, 0,0 },
			{ 20460, 8, 0,0 },
			{ 20461, 8, 0,0 },
			{ CHARA_MOTION_CMD_FIRE, 0 },
			{ CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_THROW },
			{ 20462, 8, 0,0 },
			{ 20463, 8, 0,0 },
			{ 20464, 8, 0,0 },
			{ 20465, 8, 0,0 },
			{ 20466, 8, 0,0 },
			{ 20467, 8, 0,0 },
			{ 20468, 8, 0,0 },
			{ 20469, 8, 0,0 },
			{ 20470, 8, 0,0 },
			{ 20471, 8, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY4_R_RUN },
		},
	},

	{	//	MOTION_ENEMY4_L_THROW			62
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20440, 8, 0,0 },
			{ 20441, 8, 0,0 },
			{ 20442, 8, 0,0 },
			{ 20443, 8, 0,0 },
			{ 20444, 8, 0,0 },
			{ 20445, 8, 0,0 },
			{ CHARA_MOTION_CMD_FIRE, 0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_THROW},
			{ 20446, 8, 0,0 },
			{ 20447, 8, 0,0 },
			{ 20448, 8, 0,0 },
			{ 20449, 8, 0,0 },
			{ 20450, 8, 0,0 },
			{ 20451, 8, 0,0 },
			{ 20452, 8, 0,0 },
			{ 20453, 8, 0,0 },
			{ 20454, 8, 0,0 },
			{ 20455, 8, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY4_L_RUN },
		},
	},
	
	{	//	MOTION_ENEMY4_L_STAN			63
		0,
		{	// item[]
			// fId,	fCnt, mx,my
			{ 20481, 8, 0,0 },
			{ 20481, 8, 0,0 },
			{ 20481, 8, 0,0 },
			{ 20481, 8, 0,0 },
			{ 20481, 8, 0,0 },
			{ 20481, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},

	},

	{	//	MOTION_ENEMY4_R_STAN			64
		0,
		{	// item[]
			// fId,	fCnt, mx,my
			{ 20480, 8, 0,0 },
			{ 20480, 8, 0,0 },
			{ 20480, 8, 0,0 },
			{ 20480, 8, 0,0 },
			{ 20480, 8, 0,0 },
			{ 20480, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},

	},

	{	// MOTION_ENEMY4_R_RECOVERY_STAN		65
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20498, 4, 0,0 },
			{ 20499, 4, 0,0 },
			{ 20500, 4, 0,0 },
			{ 20501, 4, 0,0 },
			{ 20502, 4, 0,0 },
			{ 20503, 4, 0,0 },
			{ 20504, 4, 0,0 },
			{ 20505, 4, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY4_R_RUN },
		},
	},

	{	// MOTION_ENEMY4_L_RECOVERY_STAN		66
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20490, 4, 0,0 },
			{ 20491, 4, 0,0 },
			{ 20492, 4, 0,0 },
			{ 20493, 4, 0,0 },
			{ 20494, 4, 0,0 },
			{ 20495, 4, 0,0 },
			{ 20496, 4, 0,0 },
			{ 20497, 4, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY4_L_RUN },
		},
	},

	{	// MOTION_ENEMY4_CUTLOCKER		67
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20510, 4, 0,0 },
			{ 20511, 4, 0,0 },
			{ 20512, 4, 0,0 },
			{ 20513, 4, 0,0 },
			{ 20514, 4, 0,0 },
			{ 20515, 4, 0,0 },
			{ 20516, 4, 0,0 },
			{ 20517, 4, 0,0 },
			{ 20518, 4, 0,0 },
			{ 20519, 4, 0,0 },
			{ 20520, 4, 0,0 },
			{ 20521, 4, 0,0 },
			{ 20522, 4, 0,0 },
			{ 20523, 4, 0,0 },
			{ 20524, 4, 0,0 },
			{ 20525, 4, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY4_R_RUN },
		},
	},


	{	//MOTION_ENEMY4_STAIR_DOWN_BACK		68
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20530, 6, 0,6 },
			{ CHARA_MOTION_CMD_LAYER, 0  },
			{ 20531, 6, 0,7 },
			{ 20532, 6, 0,7 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_STAIR+0},
			{ 20533, 6, 0,7 },
			{ 20534, 6, 0,7 },
			{ 20535, 6, 0,7 },
			{ 20536, 6, 0,7 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_STAIR + 1},
			{ 20537, 6, 0,7 },
			{ 20562, 8, -7,0 },
			{ 20563, 8, -7,0 },
			{ 20564, 8, -7,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_STAIR + 0},
			{ 20565, 8, -7,0 },
			{ 20566, 8, -7,0 },
			{ 20567, 8, -7,0 },
			{ 20568, 8, -7,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY4_STAIR_DOWN_FRONT  },
		},
	},

	{	//MOTION_ENEMY4_STAIR_DOWN_FRONT		69
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20538, 8, 0,7 },
			{ CHARA_MOTION_CMD_LAYER, 0  },
			{ 20539, 8, 0,7 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_STAIR + 2},
			{ 20540, 8, 0,7 },
			{ 20541, 8, 0,7 },
			{ 20542, 8, 0,7 },
			{ 20543, 8, 0,7 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_STAIR + 3},
			{ 20544, 8, 0,7 },
			{ 20545, 8, 0,6 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY4_L_RUN },
		},
	},

	{	//MOTION_ENEMY4_STAIR_UP_BACK		70
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20546, 8, 0,-7 },
			{ 20547, 8, 0,-7 },
			{ 20548, 8, 0,-7 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_STAIR + 3},
			{ 20549, 8, 0,-7 },
			{ 20550, 8, 0,-7 },
			{ 20551, 8, 0,-6 },
			{ CHARA_MOTION_CMD_LAYER, 0  },
			{ 20552, 8, 0,-6 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_STAIR + 2},
			{ 20553, 8, 0,-6 },
			{ 20569, 8, 7,0 },
			{ 20570, 8, 7,0 },
			{ 20571, 8, 7,0 },
			{ 20572, 8, 7,0 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_STAIR + 1},
			{ 20573, 8, 7,0 },
			{ 20574, 8, 7,0 },
			{ 20575, 8, 7,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY4_STAIR_UP_FRONT},
		},
	},

	{	//MOTION_ENEMY4_STAIR_UP_FRONT		71
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 20554, 8, 0, -6 },
			{ 20555, 8, 0, -6 },
			{ 20556, 8, 0, -6 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_STAIR + 1},
			{ 20557, 8, 0, -6 },
			{ 20558, 8, 0, -6 },
			{ 20559, 8, 0, -6 },
			{ 20560, 8, 0, -6 },
			{CHARA_MOTION_CMD_PLAYSE,SE_ENEMY4_STAIR + 0},
			{ 20561, 8, 0, -6 },
			{ CHARA_MOTION_CMD_LAYER, 0  },
			//{ CHARA_MOTION_CMD_GRAVITY, 0  },
			{ CHARA_MOTION_CMD_MOTION, MOTION_ENEMY4_L_RUN},
		},
	},

	// ìG5
	{	//	MOTION_ENEMY5_R_RUN				72
		1,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 21000, 8, 0,0 },
			{ 21001, 8, 0,0 },
			{ 21002, 8, 0,0 },
			{ 21003, 8, 0,0 },
			{ 21004, 8, 0,0 },
			{ 21005, 8, 0,0 },
			{ 21006, 8, 0,0 },
			{ 21007, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	//	MOTION_ENEMY5_L_RUN			73
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 21000, 8, 0,0 },
			{ 21001, 8, 0,0 },
			{ 21002, 8, 0,0 },
			{ 21003, 8, 0,0 },
			{ 21004, 8, 0,0 },
			{ 21005, 8, 0,0 },
			{ 21006, 8, 0,0 },
			{ 21007, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},

	//ÉMÉ~ÉbÉN
	{	//	MOTION_GIMMICK_DOOR			74
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30000, 6, 0,0 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},
	{	//	MOTION_GIMMICK_OPEN_DOOR		75
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30001, 4, 0,0 },
			{ 30002, 4, 0,0 },
			{ 30003, 4, 0,0 },
			{ 30004, 4, 0,0 },
			{ 30005, 4, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_GIMMICK_OPENED_DOOR },
		},
	},
	{	//	MOTION_GIMMICK_OPENED_DOOR		76
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30006, 6, 0,0 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},
	{	//	MOTION_GIMMICK_CLOSE_DOOR		77
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30007, 4, 0,0 },
			{ 30008, 4, 0,0 },
			{ 30009, 4, 0,0 },
			{ 30010, 4, 0,0 },
			{ 30011, 4, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_GIMMICK_DOOR },
		},
	},

	

	{	//	MOTION_GIMMICK_PC			82
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30040, 2, 0,0 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},
	{	//	MOTION_GIMMICK_OPEN_PC			83
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30041, 2, 0,0 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},
	{	//	MOTION_GIMMICK_CLOSE_PC			84
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30042, 2, 0,0 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},

	{	//	MOTION_GIMMICK_ESCAPE_PC			85
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30043, 2, 0,0 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},
	{	//	MOTION_GIMMICK_ESCAPE_OPEN_PC			86
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30044, 2, 0,0 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},
	{	//	MOTION_GIMMICK_ESCAPE_CLOSE_PC			87
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30045, 2, 0,0 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},

	{	//	MOTION_GIMMICK_CAGE			88
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30050, 2, 0,0 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},
	{	//	MOTION_GIMMICK_OPEN_CAGE		89
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30051, 2, 0,0 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},

	{	//	MOTION_GIMMICK_STAIR		90
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30060, 2, 0,0 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},
	{	//	MOTION_GIMMICK_STAIR_UP		91
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30061, 2, 0,0 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},
	{	//	MOTION_GIMMICK_STAIR_DOWN		92
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30062, 2, 0,0 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},
	{	//	MOTION_GIMMICK_LOCKER		93
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30070, 2, 0,0 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},
	{	//	MOTION_GIMMICK_OPEN_LOCKER	94
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30071, 2, 0,0 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},
	{	//	MOTION_PLAYERGIMMICK_INLOCKER	98
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30072, 2, 0,0 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},

	{	//	MOTION_GIMMICK_ELEVATOR	95
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30080, 2, 0,0 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},
	{	//	MOTION_GIMMICK_OPEN_ELEVATOR	96
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30081, 8, 0, 0 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},
	{	//	MOTION_GIMMICK_EVENT_ELEVATOR	97
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30082, 8, 0, -30 },
			{ 30082, 8, 0, -30 },
			{ 30082, 8, 0, -30 },
			{ 30082, 8, 0, -30 },
			{ 30082, 8, 0, -30 },
			{ 30082, 8, 0, -30 },
			{ 30082, 8, 0, -30 },
			{ 30082, 8, 0, -30 },
			{ 30082, 8, 0, -30 },
			{ 30082, 8, 0, -30 },
			{ 30082, 8, 0, -30 },
			{ 30082, 8, 0, -30 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},
	
	{	//	MOTION_GIMMICK_EVENT_HITRECT	99
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30090, 2, 0,0 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},
	{	//	MOTION_GIMMICK_EVENT_OPEN_HITRECT	100
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30091, 2, 0,0 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},
	{	//	MOTION_GIMMICK_EVENT_HITRECT	101
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30100, 2, 0,0 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},
	{	//	MOTION_GIMMICK_EVENT_OPEN_HITRECT	102
		0,		// mirror_lr
		{	// item[]
			 //fId, fCnt, mx,my,
			{ 30101, 2, 0,0 },
			{ CHARA_MOTION_CMD_LOOP,0 },
		},
	},

	// knife
	{	//	MOTION_EFFECT_KNIFE_R_RUN		103
		1,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 40000, 8, 0,0 },
			{ 40001, 8, 0,0 },
			{ 40002, 8, 0,0 },
			{ 40003, 8, 0,0 },
			{ 40004, 8, 0,0 },
			{ 40005, 8, 0,0 },
			{ 40006, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	//	MOTION_EFFECT_KNIFE_L_RUN	104
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 40000, 8, 0,0 },
			{ 40001, 8, 0,0 },
			{ 40002, 8, 0,0 },
			{ 40003, 8, 0,0 },
			{ 40004, 8, 0,0 },
			{ 40005, 8, 0,0 },
			{ 40006, 8, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
};

