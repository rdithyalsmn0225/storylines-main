//Database
//#define MYSQL_HOST
//#define DEBUG_MODE

#if defined MYSQL_HOST
	#define SQL_HOSTNAME "204.10.192.68"
	#define SQL_USERNAME "u687_r9HQObtwZ7"
	#define SQL_DATABASE "s687_storylines_samp"
	#define SQL_PASSWORD "f6x+!wOAb7UMmPag4MAujA0A"
#else
	#define SQL_HOSTNAME "127.0.0.1"
	#define SQL_USERNAME "root"
	#define SQL_DATABASE "idlestreet"
	#define SQL_PASSWORD ""
#endif

#define SCRIPT_REV "End of the Line v1.0"

#define PRESSED(%0) (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
#define PRESSING(%0,%1) (%0 & (%1))

#if !defined IsValidVehicle
    native IsValidVehicle(vehicleid);
#endif

#define function:%0(%1) forward %0(%1); public %0(%1)

#pragma warning disable 239, 214, 213, 208

/*=====[BODYPART]=====*/
#define BODY_PART_CHEST	(3)
#define BODY_PART_GROIN (4)
#define BODY_PART_LEFT_ARM (5)
#define BODY_PART_RIGHT_ARM (6)
#define BODY_PART_LEFT_LEG (7)
#define BODY_PART_RIGHT_LEG (8)
#define BODY_PART_HEAD (9)

/*=====[MAXIMUMS]=====*/
#define MAX_PROPERTY 				(100)
#define MAX_BUSINESS 				(100)
#define MAX_BUSINESS_PRODUCTS 		(50)
#define MAX_FACTIONS 				(30)
#define MAX_FACTION_RANKS 			(21)
#define MAX_PLAYER_VEHICLES 		(4)
#define MAX_ZONE_NAME 				(28)
#define MAX_TURFS					(600)
#define MAX_SPRAYTAGS   			(500)
#define MAX_INVENTORY				(10)
#define MAX_CAR_STORAGE 			(5)
#define MAX_DROPPED_ITEMS 			(1000)
#define MAX_LISTED_ITEMS 			(10)
#define MAX_PLAYER_CLOTHING     	(5)
#define MAX_SERVERDATA				(50)
#define MAX_CONTACTS				(20)
#define MAX_COURT					(20)
#define MAX_GARBAGE					(20)
#define MAX_RELATIONS 				(100)

LoadCustomModels()
{
    //======================================Textdraws======================================
	AddSimpleModel(-1, 19379, -2001, "misc/textdraws/idlstxt.dff", "misc/textdraws/idlstxt.txd");

	//======================================Graffiti======================================
	AddSimpleModel(-1, 1529, -2002, "graffiti/graffiti.dff", "graffiti/ballas/balla.txd");
	AddSimpleModel(-1, 1529, -2003, "graffiti/graffiti.dff", "graffiti/ballas/fyb.txd");
	AddSimpleModel(-1, 1529, -2004, "graffiti/graffiti.dff", "graffiti/ballas/ktb.txd");
	AddSimpleModel(-1, 1529, -2005, "graffiti/graffiti.dff", "graffiti/ballas/rhb.txd");
	AddSimpleModel(-1, 1529, -2006, "graffiti/graffiti.dff", "graffiti/ballas/rhb2.txd");
	AddSimpleModel(-1, 1529, -2007, "graffiti/graffiti.dff", "graffiti/ballas/rhb3.txd");

	AddSimpleModel(-1, 1529, -2008, "graffiti/graffiti.dff", "graffiti/fam/tdf.txd");
	AddSimpleModel(-1, 1529, -2009, "graffiti/graffiti.dff", "graffiti/fam/sbf.txd");

	AddSimpleModel(-1, 1529, -2010, "graffiti/graffiti.dff", "graffiti/aztecas/vla.txd");
	AddSimpleModel(-1, 1529, -2011, "graffiti/graffiti.dff", "graffiti/aztecas/vla2.txd");
	AddSimpleModel(-1, 1529, -2012, "graffiti/graffiti.dff", "graffiti/aztecas/vla3.txd");
	AddSimpleModel(-1, 1529, -2013, "graffiti/graffiti.dff", "graffiti/aztecas/vla4.txd");

	AddSimpleModel(-1, 1529, -2014, "graffiti/graffiti.dff", "graffiti/vagos/lsv.txd");
	AddSimpleModel(-1, 1529, -2015, "graffiti/graffiti.dff", "graffiti/vagos/lsv2.txd");
	AddSimpleModel(-1, 1529, -2016, "graffiti/graffiti.dff", "graffiti/vagos/lsv3.txd");
	AddSimpleModel(-1, 1529, -2017, "graffiti/graffiti.dff", "graffiti/vagos/lsv4.txd");
	AddSimpleModel(-1, 1529, -2018, "graffiti/graffiti.dff", "graffiti/vagos/lsv5.txd");
	AddSimpleModel(-1, 1529, -2019, "graffiti/graffiti.dff", "graffiti/aztecas/vla5.txd");
	//AddSimpleModel(-1, 1529, -2020, "graffiti/graffiti.dff", "graffiti/vagos/lsv7.txd");

	AddSimpleModel(-1, 1529, -2021, "graffiti/graffiti.dff", "graffiti/ballas/fyb2.txd");
	AddSimpleModel(-1, 1529, -2022, "graffiti/graffiti.dff", "graffiti/ballas/fyb3.txd");
	AddSimpleModel(-1, 1529, -2023, "graffiti/graffiti.dff", "graffiti/ballas/fyb4.txd");
	AddSimpleModel(-1, 1529, -2024, "graffiti/graffiti.dff", "graffiti/ballas/fyb5.txd");

	//========================================Skins========================================
	AddCharModel(105, 20029, "misc/skin/fam/gsf/fam1.dff", "misc/skin/fam/gsf/fam1.txd");
	AddCharModel(106, 20030, "misc/skin/fam/gsf/fam2.dff", "misc/skin/fam/gsf/fam2.txd");
	AddCharModel(107, 20031, "misc/skin/fam/gsf/fam3.dff", "misc/skin/fam/gsf/fam3.txd");

	AddCharModel(105, 20033, "misc/skin/fam/tdf/TDF1.dff", "misc/skin/fam/tdf/TDF1.txd");
	AddCharModel(106, 20034, "misc/skin/fam/tdf/TDF2.dff", "misc/skin/fam/tdf/TDF2.txd");
	AddCharModel(107, 20035, "misc/skin/fam/tdf/TDF3.dff", "misc/skin/fam/tdf/TDF3.txd");
	AddCharModel(105, 20036, "misc/skin/fam/tdf/TDF4.dff", "misc/skin/fam/tdf/TDF4.txd");

	AddCharModel(105, 20037, "misc/skin/fam/sbf/sev1.dff", "misc/skin/fam/sbf/sev1.txd");
	AddCharModel(106, 20038, "misc/skin/fam/sbf/sev2.dff", "misc/skin/fam/sbf/sev2.txd");
	AddCharModel(107, 20039, "misc/skin/fam/sbf/sev3.dff", "misc/skin/fam/sbf/sev3.txd");
	AddCharModel(105, 20040, "misc/skin/fam/sbf/sev4.dff", "misc/skin/fam/sbf/sev4.txd");

	AddCharModel(108, 20041, "misc/skin/hispanic/lsv/lsv1.dff", "misc/skin/hispanic/lsv/lsv1.txd");
	AddCharModel(109, 20042, "misc/skin/hispanic/lsv/lsv2.dff", "misc/skin/hispanic/lsv/lsv2.txd");
	AddCharModel(110, 20043, "misc/skin/hispanic/lsv/lsv3.dff", "misc/skin/hispanic/lsv/lsv3.txd");
	AddCharModel(108, 20044, "misc/skin/hispanic/lsv/lsv4.dff", "misc/skin/hispanic/lsv/lsv4.txd");
	AddCharModel(109, 20045, "misc/skin/hispanic/lsv/lsv5.dff", "misc/skin/hispanic/lsv/lsv5.txd");
	AddCharModel(110, 20046, "misc/skin/hispanic/lsv/lsv6.dff", "misc/skin/hispanic/lsv/lsv6.txd");
	AddCharModel(108, 20047, "misc/skin/hispanic/lsv/lsv7.dff", "misc/skin/hispanic/lsv/lsv7.txd");
	AddCharModel(109, 20048, "misc/skin/hispanic/lsv/lsv8.dff", "misc/skin/hispanic/lsv/lsv8.txd");
	AddCharModel(110, 20049, "misc/skin/hispanic/lsv/lsv9.dff", "misc/skin/hispanic/lsv/lsv9.txd");
	AddCharModel(108, 20050, "misc/skin/hispanic/lsv/lsv10.dff", "misc/skin/hispanic/lsv/lsv10.txd");

	AddCharModel(116, 20060, "misc/skin/hispanic/vla/vla1.dff", "misc/skin/hispanic/vla/vla1.txd");
	AddCharModel(114, 20061, "misc/skin/hispanic/vla/vla2.dff", "misc/skin/hispanic/vla/vla2.txd");
	AddCharModel(115, 20062, "misc/skin/hispanic/vla/vla3.dff", "misc/skin/hispanic/vla/vla3.txd");
	AddCharModel(116, 20063, "misc/skin/hispanic/vla/vla4.dff", "misc/skin/hispanic/vla/vla4.txd");
	AddCharModel(114, 20064, "misc/skin/hispanic/vla/vla5.dff", "misc/skin/hispanic/vla/vla5.txd");
	AddCharModel(115, 20065, "misc/skin/hispanic/vla/vla6.dff", "misc/skin/hispanic/vla/vla6.txd");
	AddCharModel(116, 20066, "misc/skin/hispanic/vla/vla7.dff", "misc/skin/hispanic/vla/vla7.txd");
	AddCharModel(115, 20067, "misc/skin/hispanic/vla/vla8.dff", "misc/skin/hispanic/vla/vla8.txd");
	AddCharModel(116, 20068, "misc/skin/hispanic/vla/vla9.dff", "misc/skin/hispanic/vla/vla9.txd");
	AddCharModel(114, 20069, "misc/skin/hispanic/vla/vla10.dff", "misc/skin/hispanic/vla/vla10.txd");
	AddCharModel(115, 20070, "misc/skin/hispanic/vla/vla11.dff", "misc/skin/hispanic/vla/vla11.txd");

	AddCharModel(300, 20071, "misc/skin/lspd/lapd1.dff", "misc/skin/lspd/lapd1.txd");
	AddCharModel(301, 20072, "misc/skin/lspd/lapd2.dff", "misc/skin/lspd/lapd2.txd");
	AddCharModel(300, 20073, "misc/skin/lspd/lapd3.dff", "misc/skin/lspd/lapd3.txd");
	AddCharModel(301, 20074, "misc/skin/lspd/lapd4.dff", "misc/skin/lspd/lapd4.txd");

	/*AddCharModel(105, 20075, "misc/skin/fam/ogf/ogf1.dff", "misc/skin/fam/ogf/ogf1.txd");
	AddCharModel(106, 20076, "misc/skin/fam/ogf/ogf2.dff", "misc/skin/fam/ogf/ogf2.txd");
	AddCharModel(107, 20077, "misc/skin/fam/ogf/ogf3.dff", "misc/skin/fam/ogf/ogf3.txd");
	AddCharModel(105, 20078, "misc/skin/fam/ogf/ogf4.dff", "misc/skin/fam/ogf/ogf4.txd");
	AddCharModel(106, 20079, "misc/skin/fam/ogf/ogf5.dff", "misc/skin/fam/ogf/ogf5.txd");
	AddCharModel(107, 20080, "misc/skin/fam/ogf/ogf6.dff", "misc/skin/fam/ogf/ogf6.txd");
	AddCharModel(105, 20081, "misc/skin/fam/ogf/ogf7.dff", "misc/skin/fam/ogf/ogf7.txd");
	AddCharModel(106, 20082, "misc/skin/fam/ogf/ogf8.dff", "misc/skin/fam/ogf/ogf8.txd");
	AddCharModel(107, 20083, "misc/skin/fam/ogf/ogf9.dff", "misc/skin/fam/ogf/ogf9.txd");
	AddCharModel(105, 20084, "misc/skin/fam/ogf/ogf10.dff", "misc/skin/fam/ogf/ogf10.txd");*/

	AddCharModel(105, 20085, "misc/skin/ballas/ktb/ballas1.dff", "misc/skin/ballas/ktb/ballas1.txd");
	AddCharModel(106, 20086, "misc/skin/ballas/ktb/ballas2.dff", "misc/skin/ballas/ktb/ballas2.txd");
	AddCharModel(107, 20087, "misc/skin/ballas/ktb/ballas3.dff", "misc/skin/ballas/ktb/ballas3.txd");

	AddCharModel(105, 20088, "misc/skin/ballas/rhb/ballas1.dff", "misc/skin/ballas/rhb/ballas1.txd");
	AddCharModel(106, 20089, "misc/skin/ballas/rhb/ballas2.dff", "misc/skin/ballas/rhb/ballas2.txd");
	AddCharModel(107, 20090, "misc/skin/ballas/rhb/ballas3.dff", "misc/skin/ballas/rhb/ballas3.txd");

	AddCharModel(105, 20091, "misc/skin/ballas/fyb/ballas1.dff", "misc/skin/ballas/fyb/ballas1.txd");
	AddCharModel(106, 20092, "misc/skin/ballas/fyb/ballas2.dff", "misc/skin/ballas/fyb/ballas2.txd");
	AddCharModel(107, 20093, "misc/skin/ballas/fyb/ballas3.dff", "misc/skin/ballas/fyb/ballas3.txd");

	AddCharModel(105, 20094, "misc/skin/ballas/tdb/ballas1.dff", "misc/skin/ballas/tdb/ballas1.txd");
	AddCharModel(106, 20095, "misc/skin/ballas/tdb/ballas2.dff", "misc/skin/ballas/tdb/ballas2.txd");
	AddCharModel(107, 20096, "misc/skin/ballas/tdb/ballas3.dff", "misc/skin/ballas/tdb/ballas3.txd");

	AddCharModel(105, 20097, "misc/skin/player/Radeetz/Radeetz.dff", "misc/skin/player/Radeetz/Radeetz.txd");
	//==========================================Weapons======================================
	AddSimpleModel(-1, 18634, -2200, "misc/weapons/hardbat.dff", "misc/weapons/hardbat.txd");
	AddSimpleModel(-1, 18634, -2201, "misc/weapons/woodbat.dff", "misc/weapons/woodbat.txd");
	AddSimpleModel(-1, 18634, -2203, "misc/weapons/bloodbat.dff", "misc/weapons/bloodbat.txd");
	AddSimpleModel(-1, 18634, -2204, "misc/weapons/glock17.dff", "misc/weapons/glock17.txd");
	AddSimpleModel(-1, 18634, -2205, "misc/weapons/glock19.dff", "misc/weapons/glock19.txd");
	AddSimpleModel(-1, 18634, -2206, "misc/weapons/glockp80.dff", "misc/weapons/glockp80.txd");
	AddSimpleModel(-1, 18634, -2207, "misc/weapons/mac11.dff", "misc/weapons/mac11.txd");
	AddSimpleModel(-1, 18634, -2208, "misc/weapons/mac10.dff", "misc/weapons/mac10.txd");
	AddSimpleModel(-1, 18634, -2209, "misc/weapons/socimi.dff", "misc/weapons/socimi.txd");
	AddSimpleModel(-1, 18634, -2210, "misc/weapons/brokenbottle.dff", "misc/weapons/brokenbottle.txd");
	AddSimpleModel(-1, 18634, -2211, "misc/weapons/glasses.dff", "misc/weapons/glasses.txd");

	//==========================================Objects==========================================
	AddSimpleModel(-1, 1575, -2500, "misc/drugs/heroine.dff", "misc/drugs/drugs.txd"); //Heroine
	AddSimpleModel(-1, 1575, -2501, "misc/drugs/marijuana.dff", "misc/drugs/drugs.txd"); //Marijuana
	AddSimpleModel(-1, 1575, -2502, "misc/drugs/cocaine.dff", "misc/drugs/drugs.txd"); //Cocaine

	AddSimpleModel(-1, 1575, -2503, "misc/bottle/champagne_bottle.dff", "misc/bottle/champagne_bottle.txd"); //Cocaine

	AddSimpleModel(-1, 1575, -2504, "misc/gym/kmb_bpress.dff", "misc/gym/gym_weights.txd"); //Heroine
	AddSimpleModel(-1, 1575, -2505, "misc/gym/kmb_dumbbell_l.dff", "misc/gym/gym_weights.txd"); //Marijuana
	AddSimpleModel(-1, 1575, -2506, "misc/gym/kmb_dumbbell_r.dff", "misc/gym/gym_weights.txd"); //Cocaine

	//==========================================Spraytags==========================================
	/*AddSimpleModel(-1, 1529, -2800, "font/font.dff", "font/result.txd");

	//==========================================Alphabet==========================================
	AddSimpleModel(-1, 1529, -2801, "font/font.dff", "font/alphabet/A.txd");
	AddSimpleModel(-1, 1529, -2802, "font/font.dff", "font/alphabet/B.txd");
	AddSimpleModel(-1, 1529, -2803, "font/font.dff", "font/alphabet/C.txd");
	AddSimpleModel(-1, 1529, -2804, "font/font.dff", "font/alphabet/D.txd");
	AddSimpleModel(-1, 1529, -2805, "font/font.dff", "font/alphabet/E.txd");
	AddSimpleModel(-1, 1529, -2806, "font/font.dff", "font/alphabet/F.txd");
	AddSimpleModel(-1, 1529, -2807, "font/font.dff", "font/alphabet/G.txd");
	AddSimpleModel(-1, 1529, -2808, "font/font.dff", "font/alphabet/H.txd");
	AddSimpleModel(-1, 1529, -2809, "font/font.dff", "font/alphabet/I.txd");
	AddSimpleModel(-1, 1529, -2810, "font/font.dff", "font/alphabet/J.txd");
	AddSimpleModel(-1, 1529, -2811, "font/font.dff", "font/alphabet/K.txd");
	AddSimpleModel(-1, 1529, -2812, "font/font.dff", "font/alphabet/L.txd");
	AddSimpleModel(-1, 1529, -2813, "font/font.dff", "font/alphabet/M.txd");
	AddSimpleModel(-1, 1529, -2814, "font/font.dff", "font/alphabet/N.txd");
	AddSimpleModel(-1, 1529, -2815, "font/font.dff", "font/alphabet/O.txd");
	AddSimpleModel(-1, 1529, -2816, "font/font.dff", "font/alphabet/P.txd");
	AddSimpleModel(-1, 1529, -2817, "font/font.dff", "font/alphabet/Q.txd");
	AddSimpleModel(-1, 1529, -2818, "font/font.dff", "font/alphabet/R.txd");
	AddSimpleModel(-1, 1529, -2819, "font/font.dff", "font/alphabet/S.txd");
	AddSimpleModel(-1, 1529, -2820, "font/font.dff", "font/alphabet/T.txd");
	AddSimpleModel(-1, 1529, -2821, "font/font.dff", "font/alphabet/U.txd");
	AddSimpleModel(-1, 1529, -2822, "font/font.dff", "font/alphabet/V.txd");
	AddSimpleModel(-1, 1529, -2823, "font/font.dff", "font/alphabet/W.txd");
	AddSimpleModel(-1, 1529, -2824, "font/font.dff", "font/alphabet/X.txd");
	AddSimpleModel(-1, 1529, -2825, "font/font.dff", "font/alphabet/Y.txd");
	AddSimpleModel(-1, 1529, -2826, "font/font.dff", "font/alphabet/Z.txd");

	//==========================================Punctuation==========================================
	AddSimpleModel(-1, 1529, -2827, "font/font.dff", "font/punctuation/equals.txd");
	AddSimpleModel(-1, 1529, -2828, "font/font.dff", "font/punctuation/exclamation.txd");
	AddSimpleModel(-1, 1529, -2829, "font/font.dff", "font/punctuation/question.txd");
	AddSimpleModel(-1, 1529, -2830, "font/font.dff", "font/punctuation/slash.txd");
	AddSimpleModel(-1, 1529, -2831, "font/font.dff", "font/punctuation/stars.txd");
	//==========================================Numbers==========================================
	AddSimpleModel(-1, 1529, -2832, "font/font.dff", "font/numbers/1.txd");
	AddSimpleModel(-1, 1529, -2833, "font/font.dff", "font/numbers/2.txd");
	AddSimpleModel(-1, 1529, -2834, "font/font.dff", "font/numbers/3.txd");
	AddSimpleModel(-1, 1529, -2835, "font/font.dff", "font/numbers/4.txd");
	AddSimpleModel(-1, 1529, -2836, "font/font.dff", "font/numbers/5.txd");
	AddSimpleModel(-1, 1529, -2837, "font/font.dff", "font/numbers/6.txd");
	AddSimpleModel(-1, 1529, -2838, "font/font.dff", "font/numbers/7.txd");
	AddSimpleModel(-1, 1529, -2839, "font/font.dff", "font/numbers/8.txd");
	AddSimpleModel(-1, 1529, -2840, "font/font.dff", "font/numbers/9.txd");
	AddSimpleModel(-1, 1529, -2841, "font/font.dff", "font/numbers/0.txd");*/

	//=======================================Clothing=======================================
	AddSimpleModel(-1, 18957, -25000, "misc/cloth/Aztecas/vlabandana.dff", "misc/cloth/Aztecas/vlabandana.txd");
	AddSimpleModel(-1, 18957, -25001, "misc/cloth/Aztecas/vlabothshoulderrag.dff", "misc/cloth/Aztecas/vlabothshoulderrag.txd");
	AddSimpleModel(-1, 18957, -25002, "misc/cloth/Aztecas/vlacholohat.dff", "misc/cloth/Aztecas/vlacholohat.txd");
	AddSimpleModel(-1, 18957, -25003, "misc/cloth/Aztecas/vlafacerag.dff", "misc/cloth/Aztecas/vlafacerag.txd");
	AddSimpleModel(-1, 18957, -25004, "misc/cloth/Aztecas/vlafamrag.dff", "misc/cloth/Aztecas/vlafamrag.txd");
	AddSimpleModel(-1, 18957, -25005, "misc/cloth/Aztecas/vlahatbandana.dff", "misc/cloth/Aztecas/vlahatbandana.txd");
	AddSimpleModel(-1, 18957, -25006, "misc/cloth/Aztecas/vlaheadrag.dff", "misc/cloth/Aztecas/vlaheadrag.txd");
	AddSimpleModel(-1, 18957, -25007, "misc/cloth/Aztecas/vlashoulderrag.dff", "misc/cloth/Aztecas/vlashoulderrag.txd");

	AddSimpleModel(-1, 18957, -25008, "misc/cloth/Ballas/ballasbackwardbandana.dff", "misc/cloth/Ballas/ballasbackwardbandana.txd");
	AddSimpleModel(-1, 18957, -25009, "misc/cloth/Ballas/ballasbothshoulderrag.dff", "misc/cloth/Ballas/ballasbothshoulderrag.txd");
	AddSimpleModel(-1, 18957, -25010, "misc/cloth/Ballas/ballasfacerag.dff", "misc/cloth/Ballas/ballasfacerag.txd");
	AddSimpleModel(-1, 18957, -25011, "misc/cloth/Ballas/ballasfamrag.dff", "misc/cloth/Ballas/ballasfamrag.txd");
	AddSimpleModel(-1, 18957, -25012, "misc/cloth/Ballas/ballasfrontbandana.dff", "misc/cloth/Ballas/ballasfrontbandana.txd");
	AddSimpleModel(-1, 18957, -25013, "misc/cloth/Ballas/ballashatbandana.dff", "misc/cloth/Ballas/ballashatbandana.txd");
	AddSimpleModel(-1, 18957, -25014, "misc/cloth/Ballas/ballasheadrag.dff", "misc/cloth/Ballas/ballasheadrag.txd");
	AddSimpleModel(-1, 18957, -25015, "misc/cloth/Ballas/ballasshoulderrag.dff", "misc/cloth/Ballas/ballasshoulderrag.txd");

	AddSimpleModel(-1, 18957, -25016, "misc/cloth/BrownPride/bpbandana.dff", "misc/cloth/BrownPride/bpbandana.txd");
	AddSimpleModel(-1, 18957, -25017, "misc/cloth/BrownPride/bpbothshoulderrag.dff", "misc/cloth/BrownPride/bpbothshoulderrag.txd");
	AddSimpleModel(-1, 18957, -25018, "misc/cloth/BrownPride/bpcholohat.dff", "misc/cloth/BrownPride/bpcholohat.txd");
	AddSimpleModel(-1, 18957, -25019, "misc/cloth/BrownPride/bpfacerag.dff", "misc/cloth/BrownPride/bpfacerag.txd");
	AddSimpleModel(-1, 18957, -25020, "misc/cloth/BrownPride/bpfamrag.dff", "misc/cloth/BrownPride/bpfamrag.txd");
	AddSimpleModel(-1, 18957, -25021, "misc/cloth/BrownPride/bphat.dff", "misc/cloth/BrownPride/bphat.txd");
	AddSimpleModel(-1, 18957, -25022, "misc/cloth/BrownPride/bpheadrag.dff", "misc/cloth/BrownPride/bpheadrag.txd");
	AddSimpleModel(-1, 18957, -25023, "misc/cloth/BrownPride/bpshoulderrag.dff", "misc/cloth/BrownPride/bpshoulderrag.txd");

	AddSimpleModel(-1, 18957, -25024, "misc/cloth/GSF/gsbackwardrag.dff", "misc/cloth/GSF/gsbackwardrag.txd");
	AddSimpleModel(-1, 18957, -25025, "misc/cloth/GSF/gsbothshoulderrag.dff", "misc/cloth/GSF/gsbothshoulderrag.txd");
	AddSimpleModel(-1, 18957, -25026, "misc/cloth/GSF/gsfacerag.dff", "misc/cloth/GSF/gsfacerag.txd");
	AddSimpleModel(-1, 18957, -25027, "misc/cloth/GSF/gsfamrag.dff", "misc/cloth/GSF/gsfamrag.txd");
	AddSimpleModel(-1, 18957, -25028, "misc/cloth/GSF/gsfrontrag.dff", "misc/cloth/GSF/gsfrontrag.txd");
	AddSimpleModel(-1, 18957, -25029, "misc/cloth/GSF/gshatonbandana.dff", "misc/cloth/GSF/gshatonbandana.txd");
	AddSimpleModel(-1, 18957, -25030, "misc/cloth/GSF/gsheadrag.dff", "misc/cloth/GSF/gsheadrag.txd");
	AddSimpleModel(-1, 18957, -25031, "misc/cloth/GSF/gsshoulderrag.dff", "misc/cloth/GSF/gsshoulderrag.txd");

	AddSimpleModel(-1, 18957, -25032, "misc/cloth/SBF/sbfacerag.dff", "misc/cloth/SBF/sbfacerag.txd");
	AddSimpleModel(-1, 18957, -25033, "misc/cloth/SBF/sbfamrag.dff", "misc/cloth/SBF/sbfamrag.txd");
	AddSimpleModel(-1, 18957, -25034, "misc/cloth/SBF/sbfbackwardbandana.dff", "misc/cloth/SBF/sbfbackwardbandana.txd");
	AddSimpleModel(-1, 18957, -25035, "misc/cloth/SBF/sbfbandanahat.dff", "misc/cloth/SBF/sbfbandanahat.txd");
	AddSimpleModel(-1, 18957, -25036, "misc/cloth/SBF/sbfbothshoulderrag.dff", "misc/cloth/SBF/sbfbothshoulderrag.txd");
	AddSimpleModel(-1, 18957, -25037, "misc/cloth/SBF/sbfheadrag.dff", "misc/cloth/SBF/sbfheadrag.txd");
	AddSimpleModel(-1, 18957, -25038, "misc/cloth/SBF/sbfrontbandana.dff", "misc/cloth/SBF/sbfrontbandana.txd");
	AddSimpleModel(-1, 18957, -25039, "misc/cloth/SBF/sbfshoulderrag.dff", "misc/cloth/SBF/sbfshoulderrag.txd");

	AddSimpleModel(-1, 18957, -25040, "misc/cloth/TDF/tdfacerag.dff", "misc/cloth/TDF/tdfacerag.txd");
	AddSimpleModel(-1, 18957, -25041, "misc/cloth/TDF/tdfamrag.dff", "misc/cloth/TDF/tdfamrag.txd");
	AddSimpleModel(-1, 18957, -25042, "misc/cloth/TDF/tdfbackwardbandana.dff", "misc/cloth/TDF/tdfbackwardbandana.txd");
	AddSimpleModel(-1, 18957, -25043, "misc/cloth/TDF/tdfbothshoulderrag.dff", "misc/cloth/TDF/tdfbothshoulderrag.txd");
	AddSimpleModel(-1, 18957, -25044, "misc/cloth/TDF/tdfhatbandana.dff", "misc/cloth/TDF/tdfhatbandana.txd");
	AddSimpleModel(-1, 18957, -25045, "misc/cloth/TDF/tdfheadrag.dff", "misc/cloth/TDF/tdfheadrag.txd");
	AddSimpleModel(-1, 18957, -25046, "misc/cloth/TDF/tdfrontrag.dff", "misc/cloth/TDF/tdfrontrag.txd");
	AddSimpleModel(-1, 18957, -25047, "misc/cloth/TDF/tdfshoulderrag.dff", "misc/cloth/TDF/tdfshoulderrag.txd");

	AddSimpleModel(-1, 18957, -25048, "misc/cloth/Vagos/vagosbandana.dff", "misc/cloth/Vagos/vagosbandana.txd");
	AddSimpleModel(-1, 18957, -25049, "misc/cloth/Vagos/vagosbothshoulderrag.dff", "misc/cloth/Vagos/vagosbothshoulderrag.txd");
	AddSimpleModel(-1, 18957, -25050, "misc/cloth/Vagos/vagoscholohat.dff", "misc/cloth/Vagos/vagoscholohat.txd");
	AddSimpleModel(-1, 18957, -25051, "misc/cloth/Vagos/vagosfacerag.dff", "misc/cloth/Vagos/vagosfacerag.txd");
	AddSimpleModel(-1, 18957, -25052, "misc/cloth/Vagos/vagosfamrag.dff", "misc/cloth/Vagos/vagosfamrag.txd");
	AddSimpleModel(-1, 18957, -25053, "misc/cloth/Vagos/vagoshatbandana.dff", "misc/cloth/Vagos/vagoshatbandana.txd");
	AddSimpleModel(-1, 18957, -25054, "misc/cloth/Vagos/vagosheadrag.dff", "misc/cloth/Vagos/vagosheadrag.txd");
	AddSimpleModel(-1, 18957, -25055, "misc/cloth/Vagos/vagosshoulderrag.dff", "misc/cloth/Vagos/vagosshoulderrag.txd");

	AddSimpleModel(-1, 18957, -25056, "misc/cloth/ogchain.dff", "misc/cloth/ogchain.txd");
	AddSimpleModel(-1, 18957, -25057, "misc/cloth/ogsunglasses.dff", "misc/cloth/ogsunglasses.txd");
	AddSimpleModel(-1, 18957, -25058, "misc/cloth/balaclava.dff", "misc/cloth/balaclava.txd");


	AddSimpleModel(-1, 18957, -25059, "misc/cloth/Hats&Glasses/WuzimuGlasses.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25060, "misc/cloth/Hats&Glasses/VLACap.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25061, "misc/cloth/Hats&Glasses/USAFaceRag.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25062, "misc/cloth/Hats&Glasses/USAbandana.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25063, "misc/cloth/Hats&Glasses/SouthernFaceRag.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25064, "misc/cloth/Hats&Glasses/SouthernBandana.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25065, "misc/cloth/Hats&Glasses/SkullyCap.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25066, "misc/cloth/Hats&Glasses/SBFCap.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25067, "misc/cloth/Hats&Glasses/SaintsCap.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25068, "misc/cloth/Hats&Glasses/RyderGlasses.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25069, "misc/cloth/Hats&Glasses/RyderCap.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25070, "misc/cloth/Hats&Glasses/RHBCap.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25071, "misc/cloth/Hats&Glasses/PimpGlasses.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25072, "misc/cloth/Hats&Glasses/OGSunglasses.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25073, "misc/cloth/Hats&Glasses/MexicanFaceRag.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25074, "misc/cloth/Hats&Glasses/MexicanBandana.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25075, "misc/cloth/Hats&Glasses/LSVCap.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25076, "misc/cloth/Hats&Glasses/LSCap.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25077, "misc/cloth/Hats&Glasses/KushCap.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25078, "misc/cloth/Hats&Glasses/KTBCap.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25079, "misc/cloth/Hats&Glasses/HandsomeGlasses.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25080, "misc/cloth/Hats&Glasses/GSFCap.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25081, "misc/cloth/Hats&Glasses/GangstaCap.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25082, "misc/cloth/Hats&Glasses/FYBCap.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25083, "misc/cloth/Hats&Glasses/FAMALAYCap.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25084, "misc/cloth/Hats&Glasses/FaceMask2.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25085, "misc/cloth/Hats&Glasses/FaceMask1.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25086, "misc/cloth/Hats&Glasses/DribblersCap.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25087, "misc/cloth/Hats&Glasses/BigSmokeGlasses.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25089, "misc/cloth/Hats&Glasses/BigSmokeCap.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25090, "misc/cloth/Hats&Glasses/BdupCap.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");
	AddSimpleModel(-1, 18957, -25091, "misc/cloth/Hats&Glasses/BALLACap.dff", "misc/cloth/Hats&Glasses/hats&glasses.txd");


	AddSimpleModel(-1, 18957, -25092, "misc/cloth/Chains&Watches/Watches/yellowwatch.dff", "misc/cloth/Chains&Watches/Watches/Watches.txd");
	AddSimpleModel(-1, 18957, -25093, "misc/cloth/Chains&Watches/Watches/silverwatch.dff", "misc/cloth/Chains&Watches/Watches/Watches.txd");
	AddSimpleModel(-1, 18957, -25094, "misc/cloth/Chains&Watches/Watches/rolexwatch.dff", "misc/cloth/Chains&Watches/Watches/Watches.txd");
	AddSimpleModel(-1, 18957, -25095, "misc/cloth/Chains&Watches/Watches/purplewatch.dff", "misc/cloth/Chains&Watches/Watches/Watches.txd");
	AddSimpleModel(-1, 18957, -25096, "misc/cloth/Chains&Watches/Watches/greenwatch.dff", "misc/cloth/Chains&Watches/Watches/Watches.txd");
	AddSimpleModel(-1, 18957, -25097, "misc/cloth/Chains&Watches/Watches/goldenwatch.dff", "misc/cloth/Chains&Watches/Watches/Watches.txd");
	AddSimpleModel(-1, 18957, -25098, "misc/cloth/Chains&Watches/Watches/fancysilverwatch.dff", "misc/cloth/Chains&Watches/Watches/Watches.txd");
	AddSimpleModel(-1, 18957, -25099, "misc/cloth/Chains&Watches/Watches/fancygoldenwatch.dff", "misc/cloth/Chains&Watches/Watches/Watches.txd");
	AddSimpleModel(-1, 18957, -25100, "misc/cloth/Chains&Watches/Watches/darkgreenwatch.dff", "misc/cloth/Chains&Watches/Watches/Watches.txd");
	AddSimpleModel(-1, 18957, -25101, "misc/cloth/Chains&Watches/Watches/darkbluewatch.dff", "misc/cloth/Chains&Watches/Watches/Watches.txd");
	AddSimpleModel(-1, 18957, -25102, "misc/cloth/Chains&Watches/Watches/brownwatch.dff", "misc/cloth/Chains&Watches/Watches/Watches.txd");
	AddSimpleModel(-1, 18957, -25103, "misc/cloth/Chains&Watches/Watches/blackwatch.dff", "misc/cloth/Chains&Watches/Watches/Watches.txd");

	AddSimpleModel(-1, 18957, -25104, "misc/cloth/Chains&Watches/Chains/69chain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25105, "misc/cloth/Chains&Watches/Chains/Africanecklace.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25106, "misc/cloth/Chains&Watches/Chains/blingblingchain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25107, "misc/cloth/Chains&Watches/Chains/BOSSchain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25108, "misc/cloth/Chains&Watches/Chains/crosschain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25109, "misc/cloth/Chains&Watches/Chains/CROWNchain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25110, "misc/cloth/Chains&Watches/Chains/discchain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25111, "misc/cloth/Chains&Watches/Chains/dogtagchain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25112, "misc/cloth/Chains&Watches/Chains/dollarchain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25113, "misc/cloth/Chains&Watches/Chains/doublechains.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25114, "misc/cloth/Chains&Watches/Chains/doublecrosschain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25115, "misc/cloth/Chains&Watches/Chains/doublegoldchains.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25116, "misc/cloth/Chains&Watches/Chains/GANGSTAchain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25117, "misc/cloth/Chains&Watches/Chains/Gchain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25118, "misc/cloth/Chains&Watches/Chains/goldenlipschain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25119, "misc/cloth/Chains&Watches/Chains/goldsilverchain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25120, "misc/cloth/Chains&Watches/Chains/GUNchain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25121, "misc/cloth/Chains&Watches/Chains/jesuschain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25122, "misc/cloth/Chains&Watches/Chains/jesuscrosschain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25123, "misc/cloth/Chains&Watches/Chains/KINGchain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25124, "misc/cloth/Chains&Watches/Chains/LSchain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25125, "misc/cloth/Chains&Watches/Chains/marijuanachain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25126, "misc/cloth/Chains&Watches/Chains/middlefingerchain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25127, "misc/cloth/Chains&Watches/Chains/REALNIGGA_Chain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25128, "misc/cloth/Chains&Watches/Chains/saintschain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25129, "misc/cloth/Chains&Watches/Chains/shortbronzechain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25130, "misc/cloth/Chains&Watches/Chains/shortgoldenchain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25131, "misc/cloth/Chains&Watches/Chains/shortsilverchain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25132, "misc/cloth/Chains&Watches/Chains/shortgoldenlipschain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25133, "misc/cloth/Chains&Watches/Chains/shortsilverlipschain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25134, "misc/cloth/Chains&Watches/Chains/silverlipschain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25135, "misc/cloth/Chains&Watches/Chains/sneakerschain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25136, "misc/cloth/Chains&Watches/Chains/thickgoldenchain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25137, "misc/cloth/Chains&Watches/Chains/thicksilverchain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25138, "misc/cloth/Chains&Watches/Chains/thinsilverchain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25139, "misc/cloth/Chains&Watches/Chains/UZIchain.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");
	AddSimpleModel(-1, 18957, -25140, "misc/cloth/Chains&Watches/Chains/worldismine.dff", "misc/cloth/Chains&Watches/Chains/Chains.txd");

	AddSimpleModel(-1, 18957, -25141, "misc/cloth/Bracelets&Earrings/doublegoldenearring.dff", "misc/cloth/Bracelets&Earrings/bracelets&earrings.txd");
	AddSimpleModel(-1, 18957, -25142, "misc/cloth/Bracelets&Earrings/doublesilverearring.dff", "misc/cloth/Bracelets&Earrings/bracelets&earrings.txd");
	AddSimpleModel(-1, 18957, -25143, "misc/cloth/Bracelets&Earrings/doubleweedearring.dff", "misc/cloth/Bracelets&Earrings/bracelets&earrings.txd");
	AddSimpleModel(-1, 18957, -25144, "misc/cloth/Bracelets&Earrings/goldenlipbracelet.dff", "misc/cloth/Bracelets&Earrings/bracelets&earrings.txd");
	AddSimpleModel(-1, 18957, -25145, "misc/cloth/Bracelets&Earrings/goldenthickbracelet.dff", "misc/cloth/Bracelets&Earrings/bracelets&earrings.txd");
	AddSimpleModel(-1, 18957, -25146, "misc/cloth/Bracelets&Earrings/silverlipbracelet.dff", "misc/cloth/Bracelets&Earrings/bracelets&earrings.txd");
	AddSimpleModel(-1, 18957, -25147, "misc/cloth/Bracelets&Earrings/silverthickbracelet.dff", "misc/cloth/Bracelets&Earrings/bracelets&earrings.txd");
	AddSimpleModel(-1, 18957, -25148, "misc/cloth/Bracelets&Earrings/singlegoldenearring.dff", "misc/cloth/Bracelets&Earrings/bracelets&earrings.txd");
	AddSimpleModel(-1, 18957, -25149, "misc/cloth/Bracelets&Earrings/singlesilverearring.dff", "misc/cloth/Bracelets&Earrings/bracelets&earrings.txd");
	AddSimpleModel(-1, 18957, -25150, "misc/cloth/Bracelets&Earrings/singleweedearring.dff", "misc/cloth/Bracelets&Earrings/bracelets&earrings.txd");

	AddSimpleModel(-1, 18957, -25151, "misc/cloth/Rings/bluering.dff", "misc/cloth/Rings/ringtextures.txd");
	AddSimpleModel(-1, 18957, -25152, "misc/cloth/Rings/bronzeage.dff", "misc/cloth/Rings/ringtextures.txd");
	AddSimpleModel(-1, 18957, -25153, "misc/cloth/Rings/goldnsilver.dff", "misc/cloth/Rings/ringtextures.txd");
	AddSimpleModel(-1, 18957, -25154, "misc/cloth/Rings/greenring.dff", "misc/cloth/Rings/ringtextures.txd");
	AddSimpleModel(-1, 18957, -25155, "misc/cloth/Rings/purplering.dff", "misc/cloth/Rings/ringtextures.txd");
	AddSimpleModel(-1, 18957, -25156, "misc/cloth/Rings/redring.dff", "misc/cloth/Rings/ringtextures.txd");
	AddSimpleModel(-1, 18957, -25157, "misc/cloth/Rings/silver.dff", "misc/cloth/Rings/ringtextures.txd");

	//==========================================MAPSSSS==========================================
	//AddSimpleModel(-1, 5474, -25551, "maps/bridge/bridgerail.dff", "maps/bridge/bridge.txd");
	//AddSimpleModel(-1, 5474, -25552, "maps/bridge/idlewoodbridge.dff", "maps/bridge/bridge.txd");
	AddSimpleModel(-1, 5474, -25553, "maps/jefferson/jeffersonmotel.dff", "maps/jefferson/jeffersonmotel.txd");
	AddSimpleModel(-1, 5474, -25554, "maps/jefferson/jeffersonmotelalp.dff", "maps/jefferson/jeffersonmotelalp.txd");
	AddSimpleModel(-1, 5474, -25555, "maps/pizzastack/pizzastack.dff", "maps/pizzastack/pizzastack.txd");

	//AddSimpleModel(-1, 5474, -25558, "maps/seville/sevilleenex.dff", "maps/seville/sevilleenex.txd");
	//AddSimpleModel(-1, 5474, -25559, "maps/frontyard/frontyard.dff", "maps/frontyard/frontyard.txd");
	AddSimpleModel(-1, 5474, -25572, "maps/frontyard/idleplaza.dff", "maps/frontyard/idleplaza.txd");
	//AddSimpleModel(-1, 5474, -25560, "maps/bahamas/bahamas.dff", "maps/bahamas/bahamas.txd");
	AddSimpleModel(-1, 5474, -25562, "maps/seville/sbf_vp.dff", "maps/seville/sevtextures.txd");
	AddSimpleModel(-1, 5474, -25563, "maps/seville/sbf4_vp.dff", "maps/seville/sevtextures.txd");
	//AddSimpleModel(-1, 5474, -25565, "maps/tdf/tdf.dff", "maps/tdf/tdf.txd");
	//AddSimpleModel(-1, 5474, -25566, "maps/tdf/tdfint.dff", "maps/tdf/tdf.txd");
	AddSimpleModel(-1, 1923, -25567, "maps/crenshaw/crenshawfurn.dff", "maps/crenshaw/crenshawfurn.txd");
	AddSimpleModel(-1, 1923, -25568, "maps/crenshaw/crenshawmisc.dff", "maps/crenshaw/crenshawmisc.txd");
	AddSimpleModel(-1, 1923, -25569, "maps/crenshaw/crenshawgr.dff", "maps/crenshaw/crenshawgr.txd");
	AddSimpleModel(-1, 8674, -25570, "maps/crenshaw/crenshawalp.dff", "maps/crenshaw/crenshawalp.txd");
	AddSimpleModel(-1, 1923, -25571, "maps/crenshaw/crenshawex.dff", "maps/crenshaw/crenshawex.txd");
	AddSimpleModel(-1, 1923, -25573, "maps/elcorona/elcflatex2.dff", "maps/elcorona/elcflatex2.txd");
	AddSimpleModel(-1, 1923, -25574, "maps/elcorona/elcflatex.dff", "maps/elcorona/elcflatex.txd");
	AddSimpleModel(-1, 19478, -25575, "maps/elcorona/elcflatalp.dff", "maps/elcorona/elcflatalp.txd");
	AddSimpleModel(-1, 1923, -25576, "maps/elcorona/elcflatfurn3.dff", "maps/elcorona/elcflatfurn3.txd");
	AddSimpleModel(-1, 1923, -25577, "maps/elcorona/elcflatfurn2.dff", "maps/elcorona/elcflatfurn2.txd");
	AddSimpleModel(-1, 1923, -25578, "maps/elcorona/elcflatfurn.dff", "maps/elcorona/elcflatfurn.txd");
	AddSimpleModel(-1, 1923, -25579, "maps/elcorona/elcflatmisc.dff", "maps/elcorona/elcflatmisc.txd");
	AddSimpleModel(-1, 1923, -25580, "maps/elcorona/elcflatmisc.dff", "maps/elcorona/elcflatmisc2.txd");
	AddSimpleModel(-1, 19379, -25581, "maps/lsv/lsvmisc6.dff", "maps/lsv/lsvmisc6.txd");
	AddSimpleModel(-1, 19379, -25582, "maps/lsv/lsvex3.dff", "maps/lsv/lsvex3.txd");
	AddSimpleModel(-1, 19379, -25583, "maps/lsv/lsvmisc5.dff", "maps/lsv/lsvmisc5.txd");
	AddSimpleModel(-1, 19325, -25584, "maps/lsv/lsvalp.dff", "maps/lsv/lsvalp.txd");
	AddSimpleModel(-1, 19379, -25585, "maps/lsv/lsvfurn.dff", "maps/lsv/lsvfurn.txd");
	AddSimpleModel(-1, 19379, -25586, "maps/lsv/lsvint2.dff", "maps/lsv/lsvint2.txd");
	AddSimpleModel(-1, 19379, -25587, "maps/lsv/lsvint.dff", "maps/lsv/lsvint.txd");
	AddSimpleModel(-1, 19379, -25588, "maps/lsv/lsvex2.dff", "maps/lsv/lsvex2.txd");
	AddSimpleModel(-1, 19379, -25589, "maps/lsv/lsvex.dff", "maps/lsv/lsvex.txd");
	AddSimpleModel(-1, 19379, -25590, "maps/lsv/lsvmisc3.dff", "maps/lsv/lsvmisc3.txd");
	AddSimpleModel(-1, 19379, -25591, "maps/lsv/lsvmisc2.dff", "maps/lsv/lsvmisc2.txd");
	AddSimpleModel(-1, 19379, -25592, "maps/lsv/lsvmisc.dff", "maps/lsv/lsvmisc.txd");
	//AddSimpleModel(-1, 19379, -25593, "maps/tdb/tdbenex.dff", "maps/tdb/tdbenex.txd");
	//AddSimpleModel(-1, 19379, -25594, "maps/ganton/gantonflatex.dff", "maps/ganton/gantonflatex.txd");
	//AddSimpleModel(-1, 19379, -25595, "maps/ganton/gantonflatint.dff", "maps/ganton/gantonflatint.txd");
	AddSimpleModel(-1, 19379, -25596, "maps/pizzastack/pizzastack.dff", "maps/pizzastack/pizzastack.txd");
	AddSimpleModel(-1, 19379, -25597, "maps/cluckinbell/cluckinbell1.dff", "maps/cluckinbell/cluckinbell1.txd");
	AddSimpleModel(-1, 19379, -25598, "maps/cluckinbell/cluckinbell2.dff", "maps/cluckinbell/cluckinbell2.txd");
	AddSimpleModel(-1, 19379, -25599, "maps/donut/donut.dff", "maps/donut/donut.txd");
	AddSimpleModel(-1, 19379, -25600, "maps/donut/donutint.dff", "maps/donut/donutint.txd");
	AddSimpleModel(-1, 5430, -25601, "maps/idleliquor/idleliquor.dff", "maps/idleliquor/idleliquor.txd");
	AddSimpleModel(-1, 1923, -25602, "maps/ganton24/ganton24.dff", "maps/ganton24/ganton24.txd");
    AddSimpleModel(-1, 1923, -25603, "maps/ganton24/ganton24_objects.dff",  "maps/ganton24/ganton24_objects.txd");

	AddSimpleModel(-1, 5474, -25604, "maps/westmont/reyo_westmont1.dff", "maps/westmont/reyo_westmont1.txd");
	AddSimpleModel(-1, 5474, -25605, "maps/westmont/reyo_westmont2.dff", "maps/westmont/reyo_westmont2.txd");
	AddSimpleModel(-1, 5474, -25606, "maps/westmont/reyo_wm_bits.dff", "maps/westmont/reyo_wm_bits.txd");
	AddSimpleModel(-1, 5474, -25607, "maps/westmont/w_bits2.dff", "maps/westmont/w_bits2.txd");
	AddSimpleModel(-1, 5474, -25608, "maps/westmont/westmont_4.dff", "maps/westmont/westmont.txd");
	AddSimpleModel(-1, 5474, -25609, "maps/westmont/westmont2.dff", "maps/westmont/westmont.txd");

	AddSimpleModel(-1, 5474, -25610, "maps/alhambra/alhambra_roads.dff",          "maps/alhambra/alhambra_roads.txd");
    AddSimpleModel(-1, 5474, -25611, "maps/alhambra/alhambra_1.dff",              "maps/alhambra/alhambra_1.txd");
    AddSimpleModel(-1, 5474, -25612, "maps/alhambra/alhambra_2.dff",              "maps/alhambra/alhambra_2.txd");
    AddSimpleModel(-1, 5474, -25613, "maps/alhambra/alhambra_3.dff",              "maps/alhambra/alhambra_3.txd");
    AddSimpleModel(-1, 5474, -25614, "maps/alhambra/alhambra_4.dff",              "maps/alhambra/alhambra_4.txd");
    AddSimpleModel(-1, 5474, -25615, "maps/alhambra/alhambra_sm_car.dff",         "maps/alhambra/alhambra_sm_car.txd");
    AddSimpleModel(-1, 5474, -25616, "maps/alhambra/alhambra_projects.dff",       "maps/alhambra/alhambra_projects.txd");
    AddSimpleModel(-1, 5474, -25617, "maps/alhambra/alhambra_houses.dff",         "maps/alhambra/alhambra_houses.txd");
    AddSimpleModel(-1, 5474, -25618, "maps/alhambra/alhambra_bits.dff",           "maps/alhambra/alhambra_bits.txd");
    AddSimpleModel(-1, 8674, -25619, "maps/alhambra/alhambra_alphas.dff",         "maps/alhambra/alhambra_alphas.txd");
	AddSimpleModel(-1, 5474, -25620,   "maps/alhambra/alley_bits.dff",            "maps/alhambra/alley_bits.txd");
    return 1;
}