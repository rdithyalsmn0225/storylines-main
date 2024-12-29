//STATIC OBJECTS
new tmpobjid;

RemoveObjects(playerid)
{
    //Industrial
    RemoveBuildingForPlayer(playerid, 3776, 902.335, -1191.140, 25.039, 0.250);
    RemoveBuildingForPlayer(playerid, 3777, 902.335, -1191.140, 25.039, 0.250);
    RemoveBuildingForPlayer(playerid, 3776, 868.132, -1191.140, 25.039, 0.250);
    RemoveBuildingForPlayer(playerid, 3777, 868.132, -1191.140, 25.039, 0.250);
    RemoveBuildingForPlayer(playerid, 5864, 849.914, -1196.689, 19.406, 0.250);
    RemoveBuildingForPlayer(playerid, 5982, 849.914, -1196.689, 19.406, 0.250);
    RemoveBuildingForPlayer(playerid, 3776, 831.960, -1191.140, 25.039, 0.250);
    RemoveBuildingForPlayer(playerid, 3777, 831.960, -1191.140, 25.039, 0.250);
    RemoveBuildingForPlayer(playerid, 3623, 2618.860, -2429.300, 17.070, 0.250);
    RemoveBuildingForPlayer(playerid, 3709, 2618.860, -2429.300, 17.070, 0.250);
    RemoveBuildingForPlayer(playerid, 3623, 2639.550, -2429.300, 17.070, 0.250);
    RemoveBuildingForPlayer(playerid, 3709, 2639.550, -2429.300, 17.070, 0.250);

	//Reworked Maps
}

stock InsertObjects()
{
    //Industrial
    tmpobjid = CreateDynamicObject(19482, 2610.919921, -2443.353027, 16.571224, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.0, 300.0); 
    SetDynamicObjectMaterialText(tmpobjid, 0, "{000000}F&M FACTORIES", 120, "Ariel", 40, 1, 0, 0, 1);
    tmpobjid = CreateDynamicObject(19482, 924.989379, -1222.038208, 24.325054, 0.000000, 0.000000, 0.199999, -1, -1, -1, 300.0, 300.0); 
    SetDynamicObjectMaterialText(tmpobjid, 0, "{000000}Waterford Industries", 120, "Ariel", 60, 1, 0, 0, 1);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    tmpobjid = CreateDynamicObject(17012, 871.871276, -1181.831298, 21.023527, 0.000000, 0.000000, 810.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(5864, 849.914001, -1196.689941, 19.406299, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(996, 874.250671, -1210.277954, 16.656602, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(996, 859.509521, -1210.277954, 16.656602, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(1215, 895.288696, -1210.301635, 16.476573, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(1215, 893.597290, -1210.301635, 16.476573, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(1215, 891.636657, -1210.301635, 16.476573, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(1215, 885.998168, -1210.301635, 16.476573, 0.000000, 0.000014, 0.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(1215, 884.306762, -1210.301635, 16.476573, 0.000000, 0.000014, 0.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(1215, 882.346130, -1210.301635, 16.476573, 0.000000, 0.000014, 0.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(1215, 858.064025, -1210.301635, 16.476573, 0.000000, 0.000022, 0.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(1215, 856.372619, -1210.301635, 16.476573, 0.000000, 0.000022, 0.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(1215, 854.411987, -1210.301635, 16.476573, 0.000000, 0.000022, 0.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(996, 832.713623, -613.108459, 16.035934, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(996, 827.493469, -612.959106, 16.035934, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(1215, 832.386657, -605.669921, 15.855940, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(1215, 827.725891, -605.669921, 15.855940, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(1215, 829.986450, -605.669921, 15.855940, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(996, 822.762695, -612.959106, 16.035934, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(996, 817.552062, -612.959106, 16.035934, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(1215, 822.494506, -605.669921, 15.855940, 0.000000, 0.000007, 0.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(1215, 817.833740, -605.669921, 15.855940, 0.000000, 0.000007, 0.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(1215, 820.094299, -605.669921, 15.855940, 0.000000, 0.000007, 0.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(10843, 2627.738281, -2433.696289, 20.462427, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(1508, 2610.644287, -2443.351318, 14.271495, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(994, 2607.096923, -2443.376220, 12.631551, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(994, 2607.096923, -2435.392822, 12.631551, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(3576, 2612.677001, -2424.440429, 14.100787, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
    tmpobjid = CreateDynamicObject(3576, 2609.904296, -2419.040527, 14.100787, 0.000000, 0.000000, -45.300006, -1, -1, -1, 300.0, 300.0); 

	// customstore
	tmpobjid = CreateDynamicObject(19379, -49.815429, 2.279375, 202.177368, 0.000000, 90.000007, 0.000000, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14709, "lamidint2", "mp_apt1_bathfloor1", 0);
	tmpobjid = CreateDynamicObject(19379, -55.065471, 2.279375, 201.287368, 0.000000, 180.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12855, "cunte_cop", "sw_brick05", 0);
	tmpobjid = CreateDynamicObject(19379, -45.385490, 2.279375, 201.287368, 0.000000, 180.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12855, "cunte_cop", "sw_brick05", 0);
	tmpobjid = CreateDynamicObject(19379, -50.235412, 6.969374, 201.287368, 0.000007, 180.000000, 89.999977, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12855, "cunte_cop", "sw_brick05", 0);
	tmpobjid = CreateDynamicObject(19379, -49.815429, 2.279375, 206.467239, 0.000000, 270.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3895, "inditaly", "tenwhitebrick64", 0);
	tmpobjid = CreateDynamicObject(19379, -50.235412, -2.610626, 201.287368, 0.000007, 180.000000, 89.999977, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12855, "cunte_cop", "sw_brick05", 0);
	tmpobjid = CreateDynamicObject(19482, -50.017234, -2.499486, 203.583389, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4227, "graffiti_lan01", "cleargraf01_LA", 0);
	tmpobjid = CreateDynamicObject(19482, -51.497234, 6.860522, 203.653396, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4981, "wiresetc2_las", "ganggraf03_LA", 0);
	tmpobjid = CreateDynamicObject(3034, -45.481777, -0.496737, 203.863327, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12946, "ce_bankalley1", "newindow13", 0);
	tmpobjid = CreateDynamicObject(3034, -45.481777, 5.023260, 203.863327, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12946, "ce_bankalley1", "newindow13", 0);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateDynamicObject(1893, -47.715503, 4.682677, 206.903854, 0.000000, 0.000007, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, -53.595478, 4.682677, 206.903854, 0.000000, 0.000007, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, -47.715503, 0.022679, 206.903854, 0.000000, 0.000015, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, -53.595478, 0.022679, 206.903854, 0.000000, 0.000015, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1522, -45.423656, 3.062862, 202.263305, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19640, -48.038055, 6.365225, 202.263305, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19640, -51.498085, 6.365225, 202.263305, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1984, -53.656913, -0.049523, 202.263305, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1843, -48.609718, -2.028584, 202.263305, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(336, -53.823436, 6.306971, 202.776947, 0.000000, 67.999992, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1338, -53.837821, 6.157994, 202.263305, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(336, -53.823436, 6.046966, 202.776947, 0.000000, 67.999992, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(336, -53.823436, 6.046966, 202.776947, 0.000000, -77.199996, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(336, -54.035209, 5.998799, 202.819335, -24.899991, -78.299980, 43.199996, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2045, -54.031200, 6.210261, 202.733230, 0.000000, 0.000000, -26.599988, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2045, -53.637767, 6.013250, 202.733230, 0.000000, 0.000000, -60.100002, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(18868, -52.299747, 6.452274, 203.703292, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(18868, -52.089771, 6.452274, 203.703292, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(18868, -51.899791, 6.452274, 203.703292, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19942, -51.657810, 6.464463, 203.722427, -94.300018, 6.400001, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19942, -51.450153, 6.521510, 203.718063, -94.300018, 6.400001, 2.499999, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19942, -51.270584, 6.509322, 203.719482, -94.300018, 6.400001, 2.499999, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19942, -51.108230, 6.538283, 203.717773, -94.300018, 6.400001, 2.499999, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19942, -50.858814, 6.521357, 203.719818, -94.300018, 6.400001, 2.499999, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19942, -50.679233, 6.509170, 203.721282, -94.300018, 6.400001, 2.499999, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1650, -52.265495, 6.807435, 203.213226, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1650, -51.785537, 6.807435, 203.213226, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19921, -51.156517, 6.358495, 202.983123, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(365, -48.848133, 6.590269, 203.843200, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(365, -48.568168, 6.590269, 203.843231, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(365, -48.298164, 6.590269, 203.843353, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(365, -47.988132, 6.590269, 203.843200, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(365, -47.698150, 6.590269, 203.843200, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(365, -47.368156, 6.590269, 203.843200, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(18634, -47.629402, 6.585095, 203.021972, 123.400016, 0.000000, 180.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(18634, -48.049369, 6.585095, 203.021972, 123.400016, 0.000000, 180.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(18634, -48.499336, 6.585095, 203.021972, 123.400016, 0.000000, 180.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2443, -54.634571, 2.880167, 202.243286, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2674, -50.789505, -1.002036, 202.283264, 0.000000, 0.000000, 35.800006, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2675, -47.150119, 4.006287, 202.323272, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2673, -53.143981, 4.302063, 202.363265, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 

	tmpobjid = CreateDynamicObject(19379, 1287.007202, 1601.979492, 454.164550, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_stationfloor", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1291.988159, 1601.979492, 452.534606, 0.000000, 180.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14668, "711c", "cj_white_wall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1287.109252, 1606.700927, 452.534606, 0.000000, 180.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14668, "711c", "cj_white_wall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1282.540405, 1601.821289, 452.534606, 0.000000, 180.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14668, "711c", "cj_white_wall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1287.401977, 1597.229492, 452.534606, 0.000000, 180.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14668, "711c", "cj_white_wall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1287.007202, 1601.979492, 457.724639, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_stationfloor", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1287.007202, 1570.650634, 454.164550, 0.000000, 90.000007, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3980, "cityhall_lan", "man_cellarfloor128", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1291.988159, 1570.650634, 452.534606, 0.000000, 180.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "wallgreyred128", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1287.109252, 1575.372070, 452.534606, 0.000007, 180.000000, 89.999977, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "wallgreyred128", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1282.540405, 1570.492431, 452.534606, 0.000000, 180.000000, 179.999954, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "wallgreyred128", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1287.401977, 1565.900634, 452.534606, 0.000007, 180.000000, 89.999977, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "wallgreyred128", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1287.007202, 1570.650634, 457.724639, 0.000000, 90.000007, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3980, "cityhall_lan", "man_cellarfloor128", 0x00000000);
	tmpobjid = CreateDynamicObject(2443, 1285.726318, 1574.935424, 454.250488, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 3, 1455, "cj_bar", "CJ_old_pish", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1287.007202, 1547.023071, 454.164550, 0.000000, 90.000022, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12844, "cos_liquorstore", "b_wtilesreflect", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1291.988159, 1547.023071, 452.534606, 0.000000, 180.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5766, "capitol_lawn", "vgs_whitewall_128", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1287.109252, 1551.744506, 452.534606, 0.000022, 180.000000, 89.999931, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5766, "capitol_lawn", "vgs_whitewall_128", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1285.911865, 1546.864868, 452.534606, 0.000000, 180.000000, 179.999862, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5766, "capitol_lawn", "vgs_whitewall_128", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1287.401977, 1542.273071, 452.534606, 0.000022, 180.000000, 89.999931, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5766, "capitol_lawn", "vgs_whitewall_128", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1287.007202, 1547.023071, 457.724639, 0.000000, 90.000022, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12844, "cos_liquorstore", "b_wtilesreflect", 0x00000000);
	tmpobjid = CreateDynamicObject(2443, 1291.567749, 1546.316284, 454.220458, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 3, 1455, "cj_bar", "CJ_BAR_TAP2", 0x00000000);
	tmpobjid = CreateDynamicObject(2443, 1291.567749, 1548.196655, 454.220458, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 3, 1455, "cj_bar", "CJ_SK_DIET_Bar", 0x00000000);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateDynamicObject(1522, 1291.975463, 1598.096557, 454.200439, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1888, 1286.674804, 1606.113403, 454.250488, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1884, 1286.711791, 1601.732177, 454.250488, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1887, 1283.108520, 1604.073486, 454.250488, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1887, 1283.108520, 1600.234619, 454.250488, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2443, 1286.786621, 1597.620727, 454.190521, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1984, 1290.403198, 1602.236450, 454.230529, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1984, 1284.320312, 1569.790405, 454.250488, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1532, 1282.626708, 1574.645629, 454.250488, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2063, 1291.636108, 1567.957031, 455.130493, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(336, 1291.524414, 1567.593994, 454.670471, 0.000000, 90.000000, 65.600021, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2045, 1291.657348, 1567.701904, 455.110382, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19914, 1291.568359, 1568.779052, 455.940673, 0.000000, 0.000000, -77.000030, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1431, 1291.552124, 1570.572998, 454.730438, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2463, 1291.843139, 1573.821899, 454.670379, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(335, 1291.394165, 1573.516845, 454.910522, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(335, 1291.509887, 1572.965454, 454.907012, -5.499998, 90.000000, 41.400001, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19583, 1291.668945, 1573.466674, 455.470489, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19583, 1291.668945, 1574.047119, 455.470489, 0.199999, 0.000000, 31.400011, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19583, 1291.689331, 1573.801879, 455.130004, 0.199999, 0.000000, -26.999992, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(18634, 1291.825805, 1573.199707, 455.850280, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(18634, 1291.625610, 1573.740234, 455.830261, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2443, 1288.338745, 1574.935424, 454.250488, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1985, 1288.017700, 1566.367187, 457.660339, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(11730, 1288.802368, 1566.245117, 454.250488, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19555, 1288.923095, 1566.136352, 454.540496, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19555, 1288.632812, 1566.136352, 454.540496, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1984, 1287.531738, 1546.203002, 454.250488, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1522, 1289.464721, 1551.695922, 454.210510, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2443, 1291.567749, 1544.255859, 454.220458, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1893, 1288.798950, 1544.707031, 458.050384, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1893, 1288.798950, 1548.538696, 458.050384, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 

	//pier
	tmpobjid = CreateDynamicObject(3250, 2891.978027, -2136.329833, 2.152460, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(12990, 2920.069335, -2144.075927, 0.414515, 0.000000, -1.600000, 81.900001, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(17068, 140.618560, -1803.330200, 0.327998, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(17068, 140.618560, -1822.819580, 0.327998, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1344, 2893.492187, -2131.497314, 3.047862, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2673, 2893.107421, -2130.260009, 2.437118, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1338, 2898.340332, -2138.911621, 3.000403, 0.000000, 0.499999, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2968, 2898.157958, -2138.212890, 2.529225, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
}

/*InsertDonatorStars() // Do not remove this under any circumstances, people paid for this...
{ 
	new g_DynamicObject[68];
	g_DynamicObject[0] = CreateDynamicObject(19483, 1020.3718, -1133.6745, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[0], 0, "Radeetz", 90, "Arial", 24, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[1] = CreateDynamicObject(19483, 974.8618, -1133.6745, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[1], 0, "BigSmoke", 90, "Arial", 24, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[2] = CreateDynamicObject(19483, 979.3926, -1133.5844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[2], 0, "MarV", 90, "Arial", 24, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[3] = CreateDynamicObject(19483, 983.9432, -1133.5344, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[3], 0, "Boris", 90, "Arial", 24, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[4] = CreateDynamicObject(19483, 988.4937, -1133.5844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[4], 0, "Nhces", 90, "Arial", 24, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[5] = CreateDynamicObject(19483, 993.0543, -1133.5844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[5], 0, "Kodok", 90, "Arial", 24, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[6] = CreateDynamicObject(19483, 997.6054, -1133.5844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[6], 0, "None", 90, "Arial", 24, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[7] = CreateDynamicObject(19483, 1002.1675, -1133.5844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[7], 0, "None", 90, "Arial", 24, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[8] = CreateDynamicObject(19483, 1006.6901, -1133.5844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[8], 0, "None", 90, "Arial", 24, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[9] = CreateDynamicObject(19483, 1011.2512, -1133.5844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[9], 0, "None", 90, "Arial", 24, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[10] = CreateDynamicObject(19483, 1015.7910, -1133.6545, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[10], 0, "None", 90, "Arial", 24, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[11] = CreateDynamicObject(19483, 997.8256, -1133.5844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[11], 0, "None", 130, "Arial", 24, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[12] = CreateDynamicObject(19483, 984.2057, -1133.5444, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[12], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[13] = CreateDynamicObject(19483, 1011.4364, -1133.5944, 22.8372, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[13], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[14] = CreateDynamicObject(19483, 1025.4821, -1133.6745, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[14], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[15] = CreateDynamicObject(19483, 1029.9742, -1133.6745, 22.8572, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[15], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[16] = CreateDynamicObject(19483, 1034.4479, -1133.6745, 22.8572, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[16], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[17] = CreateDynamicObject(19483, 1038.9393, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[17], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[18] = CreateDynamicObject(19483, 1043.4500, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[18], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[19] = CreateDynamicObject(19483, 1047.9607, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[19], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[20] = CreateDynamicObject(19483, 1052.4714, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[20], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[21] = CreateDynamicObject(19483, 1052.6014, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[21], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[22] = CreateDynamicObject(19483, 1056.9714, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[22], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[23] = CreateDynamicObject(19483, 1057.0800, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[23], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[24] = CreateDynamicObject(19483, 1061.4021, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[24], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[25] = CreateDynamicObject(19483, 1061.5321, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[25], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[26] = CreateDynamicObject(19483, 1065.9021, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[26], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[27] = CreateDynamicObject(19483, 1066.0321, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[27], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[28] = CreateDynamicObject(19483, 1070.4021, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[28], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[29] = CreateDynamicObject(19483, 1070.5321, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[29], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[30] = CreateDynamicObject(19483, 1094.7280, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[30], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[31] = CreateDynamicObject(19483, 1094.8580, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[31], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[32] = CreateDynamicObject(19483, 1099.0387, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[32], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[33] = CreateDynamicObject(19483, 1099.1687, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[33], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[34] = CreateDynamicObject(19483, 1103.3494, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[34], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[35] = CreateDynamicObject(19483, 1103.4794, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[35], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[36] = CreateDynamicObject(19483, 1107.6511, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[36], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[37] = CreateDynamicObject(19483, 1107.7811, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[37], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[38] = CreateDynamicObject(19483, 1111.9228, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[38], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[39] = CreateDynamicObject(19483, 1112.0528, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[39], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[40] = CreateDynamicObject(19483, 1116.1945, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[40], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[41] = CreateDynamicObject(19483, 1116.3245, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[41], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[42] = CreateDynamicObject(19483, 1120.4662, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[42], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[43] = CreateDynamicObject(19483, 1120.5962, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[43], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[44] = CreateDynamicObject(19483, 1124.7679, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[44], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[45] = CreateDynamicObject(19483, 1124.8979, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[45], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[46] = CreateDynamicObject(19483, 1129.0696, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[46], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[47] = CreateDynamicObject(19483, 1133.3713, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[47], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[48] = CreateDynamicObject(19483, 1137.673, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[48], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[49] = CreateDynamicObject(19483, 1141.9747, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[49], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[50] = CreateDynamicObject(19483, 1146.2764, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[50], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[51] = CreateDynamicObject(19483, 1150.5781, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[51], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[52] = CreateDynamicObject(19483, 1175.3240, -1133.7745, 22.8871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[52], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[53] = CreateDynamicObject(19483, 1175.2000, -1133.7844, 22.8972, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[53], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[54] = CreateDynamicObject(19483, 1180.4257, -1133.7745, 22.8871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[54], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[55] = CreateDynamicObject(19483, 1185.5274, -1133.7745, 22.8871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[55], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[56] = CreateDynamicObject(19483, 1185.4034, -1133.7844, 22.8972, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[56], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[57] = CreateDynamicObject(19483, 1190.8691, -1133.7745, 22.9871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[57], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[58] = CreateDynamicObject(19483, 1196.0000, -1133.6745, 22.9871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[58], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[59] = CreateDynamicObject(19483, 1201.4325, -1133.6745, 22.9871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[59], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[60] = CreateDynamicObject(19483, 1201.3100, -1133.6844, 22.9972, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[60], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[61] = CreateDynamicObject(19483, 1206.8634, -1133.6745, 22.9871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[61], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[62] = CreateDynamicObject(19483, 1212.2943, -1133.6745, 22.9871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[62], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[63] = CreateDynamicObject(19483, 1217.6252, -1133.6745, 22.9871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[63], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[64] = CreateDynamicObject(19483, 1223.0561, -1133.4745, 22.9871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[64], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[65] = CreateDynamicObject(19483, 1228.4570, -1133.4445, 22.9871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[65], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[66] = CreateDynamicObject(19483, 1233.8879, -1133.4445, 22.8871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[66], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[67] = CreateDynamicObject(19483, 1233.6879, -1133.4445, 22.8972, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[67], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
}*/

InsertAcidGunLabs(){
	tmpobjid = CreateDynamicObject(19379, 1439.623901, 1576.735717, 107.291091, 0.000000, 90.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19853, "mihouse1", "tileblue1", 0);
	tmpobjid = CreateDynamicObject(19379, 1439.623901, 1567.115356, 107.291091, 0.000000, 270.000000, 180.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19853, "mihouse1", "tileblue1", 0);
	tmpobjid = CreateDynamicObject(19379, 1434.442993, 1567.115356, 105.640968, 0.000000, 360.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4835, "airoads_las", "ws_carparkwall1", 0);
	tmpobjid = CreateDynamicObject(19379, 1434.442993, 1576.736206, 105.640968, 0.000000, 360.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4835, "airoads_las", "ws_carparkwall1", 0);
	tmpobjid = CreateDynamicObject(19379, 1444.177978, 1567.115356, 105.640968, 0.000000, 360.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4835, "airoads_las", "ws_carparkwall1", 0);
	tmpobjid = CreateDynamicObject(19379, 1444.177978, 1576.736206, 105.640968, 0.000000, 360.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4835, "airoads_las", "ws_carparkwall1", 0);
	tmpobjid = CreateDynamicObject(19379, 1439.307373, 1581.436645, 105.640968, 0.000000, 360.000000, 90.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4835, "airoads_las", "ws_carparkwall1", 0);
	tmpobjid = CreateDynamicObject(19379, 1439.307373, 1562.527832, 105.640968, 0.000000, 360.000000, 90.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4835, "airoads_las", "ws_carparkwall1", 0);
	tmpobjid = CreateDynamicObject(19379, 1439.623901, 1576.735717, 110.921104, 0.000000, 90.000007, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3615, "beachhut", "sw_flatroof01", 0);
	tmpobjid = CreateDynamicObject(19379, 1439.623901, 1567.115356, 110.921104, 0.000000, 90.000007, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3615, "beachhut", "sw_flatroof01", 0);
	tmpobjid = CreateDynamicObject(3761, 1435.289550, 1576.623413, 108.757034, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 3, 13659, "8bars", "Upt_Fence_Mesh", 0);
	tmpobjid = CreateDynamicObject(937, 1440.322631, 1577.585327, 107.826980, 0.000000, 0.000000, 90.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1560, "7_11_door", "cj_sheetmetal2", 0);
	SetDynamicObjectMaterial(tmpobjid, 1, 1560, "7_11_door", "cj_sheetmetal2", 0);
	tmpobjid = CreateDynamicObject(937, 1440.322631, 1575.724487, 107.826980, 0.000000, 0.000000, 90.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1560, "7_11_door", "cj_sheetmetal2", 0);
	SetDynamicObjectMaterial(tmpobjid, 1, 1560, "7_11_door", "cj_sheetmetal2", 0);
	tmpobjid = CreateDynamicObject(937, 1440.322631, 1573.853759, 107.826980, 0.000000, 0.000000, 90.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1560, "7_11_door", "cj_sheetmetal2", 0);
	SetDynamicObjectMaterial(tmpobjid, 1, 1560, "7_11_door", "cj_sheetmetal2", 0);
	tmpobjid = CreateDynamicObject(19899, 1443.640747, 1565.170654, 107.367027, 0.000000, 0.000000, 180.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1560, "7_11_door", "cj_sheetmetal2", 0);
	tmpobjid = CreateDynamicObject(1650, 1435.814331, 1576.156494, 107.896995, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16293, "a51_undergrnd", "Was_scrpyd_door_in_hngr", 0);
	tmpobjid = CreateDynamicObject(1650, 1435.814331, 1575.976318, 107.896995, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16293, "a51_undergrnd", "Was_scrpyd_door_in_hngr", 0);
	tmpobjid = CreateDynamicObject(1650, 1435.814331, 1575.505859, 107.896995, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16293, "a51_undergrnd", "Was_scrpyd_door_in_hngr", 0);
	tmpobjid = CreateDynamicObject(1650, 1435.814331, 1577.985107, 107.896995, 0.000000, 0.000000, -22.699996, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16293, "a51_undergrnd", "Was_scrpyd_door_in_hngr", 0);
	tmpobjid = CreateDynamicObject(1650, 1435.742553, 1578.590576, 107.896995, 0.000000, 0.000000, 6.700006, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16293, "a51_undergrnd", "Was_scrpyd_door_in_hngr", 0);
	tmpobjid = CreateDynamicObject(1650, 1435.672241, 1579.176879, 107.667167, 87.599967, 0.000000, 6.700006, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16293, "a51_undergrnd", "Was_scrpyd_door_in_hngr", 0);
	tmpobjid = CreateDynamicObject(365, 1434.935424, 1570.623168, 108.486976, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 2543, "cj_ss_3", "CJ_DOOG_FOOD", 0);
	tmpobjid = CreateDynamicObject(365, 1435.420288, 1570.783325, 108.499633, 0.000000, 80.199974, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 2543, "cj_ss_3", "CJ_DOOG_FOOD", 0);
	tmpobjid = CreateDynamicObject(365, 1434.857299, 1570.382934, 108.412513, -1.399999, 80.199974, -30.299997, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 2543, "cj_ss_3", "CJ_DOOG_FOOD", 0);
	tmpobjid = CreateDynamicObject(2002, 1435.123168, 1568.760986, 107.067016, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0);
	tmpobjid = CreateDynamicObject(19830, 1435.086059, 1568.385131, 108.316864, 0.000000, 0.000000, 90.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0);
	SetDynamicObjectMaterial(tmpobjid, 1, 1419, "break_fence3", "CJ_FRAME_Glass", 0);
	SetDynamicObjectMaterial(tmpobjid, 3, 1419, "break_fence3", "CJ_FRAME_Glass", 0);
	tmpobjid = CreateDynamicObject(19570, 1435.133422, 1569.489868, 108.317031, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 18646, "matcolours", "grey-40-percent", 0);
	tmpobjid = CreateDynamicObject(19570, 1435.143432, 1569.870239, 108.317031, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 18646, "matcolours", "grey-40-percent", 0);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1568.401367, 108.637031, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1568.401367, 108.747039, -17.200002, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1568.429687, 108.846054, -44.899997, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1568.509399, 108.927215, -82.499977, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1568.608398, 108.940261, -82.499977, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1568.707519, 108.953308, -106.699974, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1568.802978, 108.924560, -106.699974, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1568.898071, 108.895790, -121.099975, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1568.983520, 108.844139, -121.099975, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1569.211669, 108.364143, -56.199985, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1569.299682, 108.418968, -25.300012, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1569.342407, 108.509376, -25.300012, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1569.385620, 108.602752, -68.200111, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1569.496948, 108.647338, -87.300132, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1569.597045, 108.652038, -87.300132, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1569.697021, 108.656730, -97.600173, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1569.776123, 108.646141, -97.600173, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(19993, 1435.164184, 1570.174316, 108.317024, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1560, "7_11_door", "cj_sheetmetal2", 0);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1569.884887, 108.631607, -97.600173, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1569.993652, 108.617080, -115.300224, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1570.083984, 108.574356, -129.900253, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1570.154296, 108.527770, -151.600265, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(11744, 1435.061645, 1568.386718, 108.627067, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(2002, 1440.337036, 1574.234375, 107.057014, 0.000000, 0.000007, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0);
	tmpobjid = CreateDynamicObject(19830, 1440.299926, 1573.858520, 108.306861, 0.000007, 0.000000, 89.999977, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0);
	SetDynamicObjectMaterial(tmpobjid, 1, 1419, "break_fence3", "CJ_FRAME_Glass", 0);
	SetDynamicObjectMaterial(tmpobjid, 3, 1419, "break_fence3", "CJ_FRAME_Glass", 0);
	tmpobjid = CreateDynamicObject(19570, 1440.347290, 1574.963256, 108.307029, 0.000000, 0.000007, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 18646, "matcolours", "grey-40-percent", 0);
	tmpobjid = CreateDynamicObject(19570, 1440.357299, 1575.343627, 108.307029, 0.000000, 0.000007, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 18646, "matcolours", "grey-40-percent", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1573.874755, 108.627029, 0.000000, 0.000007, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1573.874755, 108.737037, -17.200000, 0.000007, 0.000002, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1573.903076, 108.836051, -44.899993, 0.000010, 0.000007, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1573.982788, 108.917213, -82.499977, 0.000058, 0.000057, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1574.081787, 108.930259, -82.499977, 0.000058, 0.000057, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1574.180908, 108.943305, -73.300018, 179.999969, 179.999969, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1574.276367, 108.914558, -73.300018, 179.999969, 179.999969, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1574.371459, 108.885787, -58.900024, 179.999969, 179.999984, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1574.456909, 108.834136, -58.900024, 179.999969, 179.999984, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1574.685058, 108.354141, -56.199985, 0.000013, 0.000011, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1574.773071, 108.408966, -25.300010, 0.000008, 0.000003, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1574.815795, 108.499374, -25.300010, 0.000008, 0.000003, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1574.859008, 108.592750, -68.200103, 0.000020, 0.000019, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1574.970336, 108.637336, -87.300125, 0.000161, 0.000161, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1575.070434, 108.642036, -87.300125, 0.000161, 0.000161, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1575.170410, 108.646728, -82.399810, 179.999938, 179.999938, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1575.249511, 108.636138, -82.399810, 179.999938, 179.999938, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(19993, 1440.378051, 1575.647705, 108.307022, 0.000000, 0.000007, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1560, "7_11_door", "cj_sheetmetal2", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1575.358276, 108.621604, -82.399810, 179.999938, 179.999938, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1575.467041, 108.607078, -64.699768, 179.999969, 179.999969, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1575.557373, 108.564353, -50.099742, 179.999984, 179.999984, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1575.627685, 108.517768, -28.399732, 179.999984, 179.999984, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(11744, 1440.275512, 1573.860107, 108.617065, 0.000000, 0.000007, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(2002, 1440.316528, 1577.772460, 107.057014, 0.000000, 0.000022, 179.999938, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0);
	tmpobjid = CreateDynamicObject(19830, 1440.353637, 1578.148315, 108.306861, 0.000022, 0.000000, -90.000038, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0);
	SetDynamicObjectMaterial(tmpobjid, 1, 1419, "break_fence3", "CJ_FRAME_Glass", 0);
	SetDynamicObjectMaterial(tmpobjid, 3, 1419, "break_fence3", "CJ_FRAME_Glass", 0);
	tmpobjid = CreateDynamicObject(19570, 1440.306274, 1577.043579, 108.307029, 0.000000, 0.000022, 179.999938, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 18646, "matcolours", "grey-40-percent", 0);
	tmpobjid = CreateDynamicObject(19570, 1440.296264, 1576.663208, 108.307029, 0.000000, 0.000022, 179.999938, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 18646, "matcolours", "grey-40-percent", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1578.132080, 108.627029, 0.000000, 0.000022, 179.999938, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1578.132080, 108.737037, -17.199996, 0.000023, 179.999969, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1578.103759, 108.836051, -44.899993, 0.000032, 179.999969, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1578.024047, 108.917213, -82.499977, 0.000175, -179.999816, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1577.925048, 108.930259, -82.499977, 0.000175, -179.999816, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1577.825927, 108.943305, -73.300010, 179.999908, -0.000132, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1577.730468, 108.914558, -73.300010, 179.999908, -0.000132, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1577.635375, 108.885787, -58.900024, 179.999938, -0.000088, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1577.549926, 108.834136, -58.900024, 179.999938, -0.000088, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1577.321777, 108.354141, -56.199985, 0.000041, -179.999954, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1577.233764, 108.408966, -25.300006, 0.000025, 179.999969, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1577.191040, 108.499374, -25.300006, 0.000025, 179.999969, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1577.147827, 108.592750, -68.200103, 0.000061, -179.999923, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1577.036499, 108.637336, -87.300125, 0.000485, -179.999496, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1576.936401, 108.642036, -87.300125, 0.000485, -179.999496, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1576.836425, 108.646728, -82.399810, 179.999816, -0.000225, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1576.757324, 108.636138, -82.399810, 179.999816, -0.000225, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(19993, 1440.275512, 1576.359130, 108.307022, 0.000000, 0.000022, 179.999938, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1560, "7_11_door", "cj_sheetmetal2", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1576.648559, 108.621604, -82.399810, 179.999816, -0.000225, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1576.539794, 108.607078, -64.699752, 179.999938, -0.000122, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1576.449462, 108.564353, -50.099735, 179.999954, -0.000085, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1576.379150, 108.517768, -28.399728, 179.999954, -0.000080, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0);
	tmpobjid = CreateDynamicObject(11744, 1440.378051, 1578.146728, 108.617065, 0.000000, 0.000022, 179.999938, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0);
	tmpobjid = CreateDynamicObject(1650, 1440.656005, 1570.204833, 108.646972, 0.000000, 0.000000, 41.299999, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16293, "a51_undergrnd", "Was_scrpyd_door_in_hngr", 0);
	tmpobjid = CreateDynamicObject(19379, 1470.164672, 1567.115356, 107.291091, 0.000000, 270.000000, 179.999954, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19853, "mihouse1", "tileblue1", 0);
	tmpobjid = CreateDynamicObject(19379, 1466.635009, 1567.115356, 105.640968, 0.000000, 360.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4835, "airoads_las", "ws_carparkwall1", 0);
	tmpobjid = CreateDynamicObject(19379, 1474.718750, 1567.115356, 105.640968, 0.000000, 360.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4835, "airoads_las", "ws_carparkwall1", 0);
	tmpobjid = CreateDynamicObject(19379, 1469.848144, 1571.877563, 105.640968, 0.000007, 360.000000, 89.999977, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4835, "airoads_las", "ws_carparkwall1", 0);
	tmpobjid = CreateDynamicObject(19379, 1469.848144, 1562.527832, 105.640968, 0.000007, 360.000000, 89.999977, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4835, "airoads_las", "ws_carparkwall1", 0);
	tmpobjid = CreateDynamicObject(19379, 1470.164672, 1567.115356, 110.921104, 0.000000, 90.000015, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3615, "beachhut", "sw_flatroof01", 0);
	tmpobjid = CreateDynamicObject(937, 1474.083618, 1563.946044, 107.837051, 0.000000, 0.000000, 90.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 1, 1560, "7_11_door", "cj_sheetmetal2", 0);
	tmpobjid = CreateDynamicObject(19900, 1472.187133, 1562.935913, 107.377029, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1560, "7_11_door", "cj_sheetmetal2", 0);
	tmpobjid = CreateDynamicObject(937, 1474.083618, 1567.976928, 107.837051, 0.000000, 0.000000, 90.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 1, 1560, "7_11_door", "cj_sheetmetal2", 0);
	tmpobjid = CreateDynamicObject(937, 1474.083618, 1570.858520, 107.837051, 0.000000, 0.000000, 90.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 1, 1560, "7_11_door", "cj_sheetmetal2", 0);
	tmpobjid = CreateDynamicObject(1522, 1471.295410, 1565.549560, 107.377029, 0.000000, 0.000000, 67.900039, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3819, "baseball_sfsx", "helipad_mesh_t", 0);
	tmpobjid = CreateDynamicObject(2974, 1466.501098, 1568.757568, 107.377029, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16293, "a51_undergrnd", "Was_scrpyd_door_in_hngr", 0);
	tmpobjid = CreateDynamicObject(19899, 1468.024291, 1566.128540, 107.377029, 0.000000, 0.000000, 90.000000, -1, 11, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1560, "7_11_door", "cj_sheetmetal2", 0);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateDynamicObject(1893, 1437.607666, 1574.722900, 111.406997, 0.000007, 0.000000, 89.999977, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, 1436.286376, 1574.722900, 111.406997, 0.000007, 0.000000, 89.999977, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, 1436.286376, 1568.118896, 111.406997, 0.000000, 0.000000, 90.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, 1437.607666, 1568.099365, 111.406997, 0.000000, 0.000000, 90.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, 1436.286376, 1564.317626, 111.406997, 0.000007, 0.000000, 89.999977, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, 1437.607666, 1564.298095, 111.406997, 0.000007, 0.000000, 89.999977, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, 1437.607666, 1578.503540, 111.406997, 0.000015, 0.000000, 89.999954, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, 1436.286376, 1578.503540, 111.406997, 0.000015, 0.000000, 89.999954, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, 1443.052856, 1574.722900, 111.406997, 0.000022, 0.000000, 89.999931, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, 1441.731567, 1574.722900, 111.406997, 0.000022, 0.000000, 89.999931, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, 1440.690551, 1568.118896, 111.406997, 0.000007, 0.000000, 89.999977, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, 1442.011840, 1568.099365, 111.406997, 0.000007, 0.000000, 89.999977, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, 1440.690551, 1564.317626, 111.406997, 0.000015, 0.000000, 89.999954, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, 1442.011840, 1564.298095, 111.406997, 0.000015, 0.000000, 89.999954, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, 1443.052856, 1579.124145, 111.406997, 0.000030, 0.000000, 89.999908, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, 1441.731567, 1579.104125, 111.406997, 0.000030, 0.000000, 89.999908, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(14578, 1442.165039, 1574.688476, 110.966880, 0.000000, 0.000000, 90.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(14882, 1446.379638, 1561.488525, 109.236976, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(14882, 1446.379638, 1568.497314, 109.236976, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(14578, 1439.143676, 1580.129882, 110.966880, 0.000000, 0.000000, 270.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(14578, 1438.453979, 1563.849853, 110.956832, 0.000000, 0.000000, 450.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(5340, 1439.370239, 1562.538696, 108.846977, 0.000000, 0.000000, 270.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19869, 1441.524414, 1571.889038, 107.347023, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(14882, 1436.965820, 1566.300659, 109.316986, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(14882, 1436.965820, 1560.552001, 109.316986, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(944, 1442.607421, 1580.622070, 108.236991, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1348, 1443.659301, 1575.938964, 108.096961, 0.000000, 0.000000, 90.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2007, 1443.582519, 1570.819824, 107.377029, 0.000000, 0.000000, 270.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2007, 1443.582519, 1569.859130, 107.377029, 0.000000, 0.000000, 270.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2007, 1443.582519, 1570.819824, 108.777000, -0.000007, -0.000000, -89.999977, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2007, 1443.582519, 1569.859130, 108.777000, -0.000007, -0.000000, -89.999977, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2418, 1435.098999, 1569.707397, 107.377029, 0.000000, 0.000000, 90.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2418, 1435.098999, 1567.837280, 107.377029, 0.000000, 0.000000, 90.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2418, 1439.942016, 1569.916748, 107.377029, 0.000000, 0.000000, 270.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2418, 1441.143188, 1569.005981, 107.367027, 0.000000, 0.000000, 450.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2958, 1435.898315, 1578.866333, 108.467025, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2958, 1435.898315, 1579.246704, 108.467025, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2958, 1435.267700, 1579.136596, 108.467025, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2958, 1435.507934, 1579.456909, 108.467025, 0.000000, 0.000000, 86.200050, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2958, 1435.898315, 1578.126953, 108.467025, 0.000000, 0.000015, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2958, 1435.898315, 1578.507324, 108.467025, 0.000000, 0.000015, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2958, 1435.267700, 1578.397216, 108.467025, 0.000000, 0.000015, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2958, 1435.507934, 1578.717529, 108.467025, 0.000015, 0.000001, 86.200004, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2958, 1435.487915, 1578.197021, 108.467025, 0.000000, 0.000022, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2958, 1435.487915, 1578.577392, 108.467025, 0.000000, 0.000022, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2958, 1434.857299, 1578.467285, 108.467025, 0.000000, 0.000022, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2958, 1435.097534, 1578.787597, 108.467025, 0.000022, 0.000001, 86.199981, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(928, 1435.397705, 1577.455444, 108.636955, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(928, 1435.397705, 1576.594970, 108.636955, 0.000000, 0.000000, 55.900005, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1575, 1435.570068, 1575.824951, 108.377037, 0.000000, 0.000000, 47.999996, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1575, 1435.485717, 1574.353149, 108.377037, 0.000000, 0.000000, -65.299995, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1575, 1435.652954, 1574.424194, 108.442527, 0.000000, 27.200010, 23.100000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1578, 1435.442993, 1574.394409, 109.157005, 0.000000, 0.000000, -44.200000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1578, 1435.426757, 1577.088867, 109.157005, 0.000000, 0.000000, -44.200000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1578, 1435.415039, 1577.894287, 109.157005, 0.000000, 0.000000, 29.299995, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19585, 1435.071777, 1568.594970, 108.727020, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19585, 1440.285644, 1574.068359, 108.717018, 0.000000, 0.000007, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19585, 1440.367919, 1577.938476, 108.717018, 0.000000, 0.000022, 179.999938, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1575, 1439.968505, 1569.893676, 108.256988, 0.000000, 0.000000, -36.299999, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1575, 1439.995239, 1568.883178, 108.256988, 0.000000, 0.000000, 55.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19585, 1440.929199, 1569.144042, 108.506965, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19585, 1441.299560, 1569.144042, 108.506965, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, 1440.109497, 1577.182250, 110.907035, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, 1440.109497, 1574.610839, 110.907035, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, 1468.148437, 1563.969726, 111.406997, 0.000015, 0.000000, 89.999954, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, 1473.563720, 1563.969726, 111.406997, 0.000030, 0.000000, 89.999908, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, 1473.563720, 1569.462524, 111.406997, 0.000030, 0.000000, 89.999908, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19869, 1473.884887, 1565.609375, 107.377029, 0.000000, 0.000007, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1893, 1468.148437, 1569.462524, 111.406997, 0.000015, 0.000000, 89.999954, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19869, 1467.485351, 1565.609375, 107.377029, 0.000000, 0.000007, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19869, 1467.485351, 1565.609375, 109.806976, 0.000000, 0.000007, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19869, 1473.884887, 1565.609375, 109.797012, 0.000000, 0.000007, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19869, 1470.702026, 1565.609375, 109.797012, 0.000000, 0.000007, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2924, 1471.296386, 1562.562622, 108.586975, 0.000000, 0.000000, 360.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1224, 1467.353393, 1563.255859, 107.977027, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1224, 1467.353393, 1563.255859, 109.136932, 0.000000, 0.000000, 450.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1221, 1467.460937, 1564.697998, 107.817024, 0.000000, 0.000000, -35.800003, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(3052, 1473.942871, 1563.287475, 108.446968, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(356, 1473.747924, 1563.951293, 108.386955, 90.000000, -108.800003, 90.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(352, 1473.912475, 1564.497314, 108.297019, 90.000000, -49.999996, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2359, 1474.465942, 1564.343505, 108.507019, 0.000000, 0.000000, 270.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2041, 1474.440307, 1567.321289, 108.527023, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2041, 1474.099975, 1567.321289, 108.527023, 0.000000, 0.000000, -37.699989, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2041, 1474.305786, 1568.651611, 108.527023, 0.000000, 0.000000, -134.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(352, 1473.847778, 1567.979614, 108.317008, 90.000000, 29.699998, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(3384, 1473.821044, 1566.330932, 108.786987, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2615, 1474.569213, 1567.978759, 109.176979, 0.000000, 0.000000, 270.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1431, 1471.037719, 1571.437866, 107.886962, 0.000000, 0.000000, 180.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(923, 1467.621582, 1571.315917, 108.246948, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(3014, 1474.196044, 1570.281372, 108.517044, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(3014, 1473.765625, 1571.391601, 108.517044, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2969, 1467.733154, 1566.127807, 108.716995, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2969, 1468.833374, 1566.127807, 109.536987, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2068, 1470.539672, 1567.722412, 110.886863, 0.000000, 0.000000, 0.000000, -1, 11, -1, 300.0, 300.0); 

}

InsertCharacterScene()
{
	tmpobjid = CreateDynamicObject(5819, 1352.558105, 894.675231, 129.997817, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 1, 9515, "bigboxtemp1", "ws_garagedoor3_white", 0);
	tmpobjid = CreateDynamicObject(19457, 1338.565551, 907.160095, 131.837829, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 9524, "blokmodb", "lightwallv256", 0);
	tmpobjid = CreateDynamicObject(19365, 1338.221313, 900.842163, 131.837783, 0.000000, 0.000000, -13.100005, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 9524, "blokmodb", "lightwallv256", 0);
	tmpobjid = CreateDynamicObject(19457, 1337.258178, 884.906677, 131.837829, 0.000000, 0.000000, 172.099929, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 9524, "blokmodb", "lightwallv256", 0);
	tmpobjid = CreateDynamicObject(19457, 1340.031860, 869.892883, 131.837829, 0.000000, 0.000000, 73.799980, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5444, "chicano10_lae", "compfence1_LAe", 0);
	tmpobjid = CreateDynamicObject(19457, 1345.175781, 905.542419, 131.837829, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 9524, "blokmodb", "lightwallv256", 0);
	tmpobjid = CreateDynamicObject(1227, 1345.346069, 897.281127, 130.977905, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1355, "break_s_bins", "CJ_RED_LEATHER", 0);
	tmpobjid = CreateDynamicObject(19457, 1343.220581, 908.015136, 131.837829, 0.000000, 0.000000, 86.799995, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 9524, "blokmodb", "lightwallv256", 0);
	tmpobjid = CreateDynamicObject(19482, 1345.917236, 897.897827, 132.327728, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5390, "glenpark7_lae", "ganggraf01_LA", 0);
	tmpobjid = CreateDynamicObject(19482, 1345.917236, 890.967346, 132.327728, 11.100001, 0.000000, 180.000000, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14801, "lee_bdupsmain", "Bdup_graf5", 0);
	tmpobjid = CreateDynamicObject(19482, 1345.917236, 884.658081, 132.327728, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14801, "lee_bdupsmain", "Bdup_graf4", 0);
	tmpobjid = CreateDynamicObject(19482, 1337.313720, 884.645141, 131.827758, 0.000000, 0.000000, -7.900002, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14801, "lee_bdupsmain", "Bdup_graf4", 0);
	tmpobjid = CreateDynamicObject(19482, 1337.577514, 886.543579, 131.630905, -10.999999, 0.000000, -7.900002, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14801, "lee_bdupsmain", "Bdup_graf2", 0);
	tmpobjid = CreateDynamicObject(19482, 1342.058715, 892.560791, 134.679885, -4.099996, 0.000000, 59.000007, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17518, "hub_alpha", "clothline1_LAe", 0);
	tmpobjid = CreateDynamicObject(19482, 1341.863769, 871.172424, 132.436294, -4.099996, 0.000000, 77.400032, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17518, "hub_alpha", "clothline1_LAe", 0);
	tmpobjid = CreateDynamicObject(1227, 1338.025512, 886.270446, 130.917831, 0.000000, 0.000000, 84.200012, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1355, "break_s_bins", "CJ_RED_LEATHER", 0);
	tmpobjid = CreateDynamicObject(19482, 1345.067504, 904.378234, 132.007797, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.0, 300.0); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4981, "wiresetc2_las", "ganggraf03_LA", 0);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateDynamicObject(6959, 1343.062377, 888.442565, 130.188995, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(3582, 1333.840332, 894.431640, 132.837661, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(3556, 1332.939208, 875.521301, 132.697799, 0.000000, 0.000000, -86.800048, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(3655, 1351.374755, 874.110717, 133.127883, 0.000000, 0.000000, 172.600006, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19457, 1345.176757, 905.542419, 135.277969, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1227, 1344.515258, 904.542236, 130.967910, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(17969, 1338.707763, 905.202514, 131.727798, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1529, 1338.416381, 901.242248, 132.473907, 14.600003, 0.000000, 166.699890, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1531, 1338.325317, 900.853942, 131.097824, -18.000001, 0.000000, 167.099838, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(18663, 1338.047973, 897.780761, 132.020065, 10.899999, 0.000000, 180.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1525, 1338.037719, 892.012329, 132.197708, -16.499994, 0.000000, 180.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1525, 1338.037719, 890.497497, 131.147857, 10.800006, 0.000000, 180.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(946, 1344.605834, 881.356323, 132.277725, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2114, 1343.675415, 880.667236, 130.217666, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(3459, 1337.116088, 881.612915, 137.237838, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1223, 1338.419433, 888.796691, 130.127761, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19834, 1338.033325, 894.523742, 131.727813, 0.000000, -13.700001, 90.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19834, 1338.033325, 894.511779, 132.702835, 0.000000, 3.799998, 90.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19834, 1338.033325, 894.661315, 131.164306, 0.000000, 7.099997, 90.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1264, 1345.490478, 892.101623, 130.547805, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1264, 1345.490478, 895.601074, 130.547805, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1264, 1344.560180, 902.861328, 130.547805, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2673, 1343.008178, 890.797180, 130.267700, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2676, 1338.806518, 888.009460, 130.277664, 0.000000, 0.000000, 109.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2675, 1343.892578, 883.978393, 130.227722, 0.000000, 0.000000, 47.099994, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2675, 1339.602539, 898.893432, 130.237701, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2673, 1344.956909, 899.518188, 130.247680, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2673, 1343.582397, 903.248779, 130.257690, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1369, 1344.186889, 901.646789, 130.717697, 0.000000, 0.000000, -66.199989, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1810, 1338.568847, 899.069824, 130.097640, 0.000000, 0.000000, 68.299980, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1810, 1339.026489, 897.132995, 130.097640, 0.000000, 0.000000, 108.899963, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1440, 1339.331054, 904.794494, 130.637817, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2673, 1338.331909, 878.856872, 130.237701, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1432, 1339.545166, 872.188232, 130.257736, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1810, 1343.979492, 876.637695, 130.037796, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1810, 1343.979492, 878.227722, 130.037796, 0.000000, 0.000000, -118.399986, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(2673, 1343.428955, 875.909912, 130.237701, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1443, 1337.624511, 877.696838, 130.777786, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
}

InsertPolice()
{
	tmpobjid = CreateDynamicObject(19466, 258.860198, 84.698295, 1003.215576, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	tmpobjid = CreateDynamicObject(19466, 258.880218, 84.728294, 1003.175537, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	tmpobjid = CreateDynamicObject(19466, 258.880218, 84.668273, 1003.175537, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	tmpobjid = CreateDynamicObject(19466, 258.880218, 84.668273, 1003.265625, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	tmpobjid = CreateDynamicObject(19466, 258.880218, 84.728294, 1003.265625, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, 258.832611, 84.716148, 1003.955505, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterialText(tmpobjid, 0, "{000000}__________", 130, "Engravers MT", 20, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, 258.832611, 84.716148, 1003.455261, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterialText(tmpobjid, 0, "{000000}__________", 130, "Engravers MT", 20, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, 258.832611, 84.716148, 1002.904724, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterialText(tmpobjid, 0, "{000000}__________", 130, "Engravers MT", 20, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, 258.832611, 84.716148, 1003.815429, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterialText(tmpobjid, 0, "{000000}___", 130, "Engravers MT", 20, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, 258.832611, 84.716148, 1003.655273, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterialText(tmpobjid, 0, "{000000}___", 130, "Engravers MT", 20, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, 258.832611, 84.716148, 1003.294921, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterialText(tmpobjid, 0, "{000000}___", 130, "Engravers MT", 20, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, 258.832611, 84.716148, 1003.104736, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterialText(tmpobjid, 0, "{000000}___", 130, "Engravers MT", 20, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, 258.832611, 84.716148, 1002.764404, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterialText(tmpobjid, 0, "{000000}___", 130, "Engravers MT", 20, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, 258.832611, 84.716148, 1002.554199, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterialText(tmpobjid, 0, "{000000}___", 130, "Engravers MT", 20, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(955, 258.471038, 89.241149, 1001.825683, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 2221, "donut_tray", "rustycoffeerap_rb", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, 1589.308349, -1602.641113, 13.882806, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterialText(tmpobjid, 0, "{ffffff}LSPD IMPOUND CENTER", 120, "Ariel", 40, 1, 0x00000000, 0x00000000, 1);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateDynamicObject(2605, 252.768478, 82.849830, 1001.845458, -0.000014, 0.000000, -89.999954, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2605, 252.768478, 84.809852, 1001.845458, -0.000014, 0.000000, -89.999954, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2610, 251.166717, 82.183959, 1002.245544, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2610, 251.646743, 82.183959, 1002.245544, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2610, 252.136749, 82.183959, 1002.245544, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2611, 250.939590, 84.451507, 1003.435546, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1806, 251.183944, 83.209732, 1001.445312, 0.000000, 0.000000, -65.800003, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1806, 251.145446, 84.684638, 1001.445312, 0.000000, 0.000000, -97.799980, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2610, 251.139831, 91.511528, 1002.225646, 0.000000, 0.000000, 360.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2610, 251.629776, 91.511528, 1002.225646, 0.000000, 0.000000, 360.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2612, 253.027206, 91.795318, 1003.156188, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(14843, 266.351989, 81.195297, 1001.280029, 0.000000, 0.000000, 89.999992, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1238, 1534.865112, -1680.832641, 12.672816, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1238, 1537.125610, -1680.832641, 12.672816, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1238, 1537.125610, -1664.409423, 12.672816, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1238, 1534.814453, -1664.409423, 12.672816, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19364, 1544.672607, -1622.196899, 14.096877, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19393, 1544.663330, -1619.165405, 14.094571, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19364, 1546.282836, -1617.765502, 14.096877, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19364, 1547.995483, -1617.764526, 14.096877, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(997, 1544.275146, -1636.067016, 12.566873, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(640, 270.138641, 77.975868, 1000.659667, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(640, 270.138641, 90.645866, 1000.659667, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2611, 270.340393, 84.164108, 1001.889282, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(4199, 1602.085083, -1618.391723, 14.531046, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2356, 1579.974853, -1634.491210, 12.559739, 0.000000, 0.000000, -27.799997, -1, -1, -1, 300.00, 300.00); 

}

InsertReworkedMaps()
{
	//Bahamas
	tmpobjid = CreateDynamicObject(11102, 2036.762695, -1286.184448, 21.856340, -0.000000, 0.000022, -0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4682, "dtbuil1_lan2", "barbershop_256", 0x00000000);
	tmpobjid = CreateDynamicObject(11102, 2036.762695, -1292.057617, 21.856340, -0.000000, 0.000022, -0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4001, "civic03_lan", "downtshop2_LAn", 0x00000000);
	tmpobjid = CreateDynamicObject(11102, 2036.762695, -1297.916137, 21.856340, -0.000000, 0.000022, -0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4001, "civic03_lan", "gymshop2_LAe", 0x00000000);
	tmpobjid = CreateDynamicObject(11102, 2036.762695, -1303.785644, 21.856340, -0.000000, 0.000022, -0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 6282, "beafron2_law2", "shutter03LA", 0x00000000);
	tmpobjid = CreateDynamicObject(1364, 2032.297851, -1285.887695, 20.719079, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 3, 16640, "a51", "concretewall22_256", 0x00000000);
	tmpobjid = CreateDynamicObject(1364, 2032.297851, -1297.968261, 20.719079, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 3, 16640, "a51", "concretewall22_256", 0x00000000);
	tmpobjid = CreateDynamicObject(1281, 2027.262084, -1297.400268, 20.734529, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 1, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 2, 18882, "hugebowls", "wallwhite2top", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 3, 18641, "flashlight1", "metalblack1-2", 0x00000000);
	tmpobjid = CreateDynamicObject(1281, 2027.262084, -1292.009887, 20.734529, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 1, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 2, 18882, "hugebowls", "wallwhite2top", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 3, 1426, "break_scaffold", "CJ_BLUE_WOOD", 0x00000000);
	tmpobjid = CreateDynamicObject(1281, 2027.262084, -1286.137817, 20.734529, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 1, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 2, 18882, "hugebowls", "wallwhite2top", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 3, 2772, "airp_prop", "CJ_red_COUNTER", 0x00000000);
	tmpobjid = CreateDynamicObject(19359, 2034.905151, -1277.002197, 21.719947, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19304, "pd_jail_door_top01", "pd_jail_door_top01", 0x00000000);
	tmpobjid = CreateDynamicObject(19359, 2027.725097, -1276.283203, 21.719947, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19304, "pd_jail_door_top01", "pd_jail_door_top01", 0x00000000);
	tmpobjid = CreateDynamicObject(19359, 2034.195922, -1309.121826, 21.559944, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19304, "pd_jail_door_top01", "pd_jail_door_top01", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, 2023.375854, -1280.443237, 21.735311, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14801, "lee_bdupsmain", "Bdup_graf4", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, 2023.375854, -1289.763427, 21.735311, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14801, "lee_bdupsmain", "Bdup_graf5", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, 2023.405883, -1297.015014, 21.735311, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5998, "sunstr_lawn", "ganggraf02_LA", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, 2007.627197, -1282.428588, 33.150306, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17504, "eastlstr_lae2", "mural07_LA", 0x00000000);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateDynamicObject(717, 2031.869018, -1292.017211, 20.095500, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1359, 2031.867797, -1294.404663, 20.570619, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1359, 2031.867797, -1289.513671, 20.570619, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1482, 2025.081176, -1301.923217, 21.330970, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(910, 2024.304931, -1301.088012, 21.069160, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(910, 2027.425903, -1301.088012, 21.069160, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1264, 2025.899291, -1301.117065, 20.349325, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1264, 2024.009155, -1302.208007, 20.349325, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1365, 2024.754760, -1273.657714, 21.012548, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(982, 1992.869995, -1271.996093, 24.214382, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1372, 1992.831054, -1271.528198, 23.104377, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2673, 1994.180786, -1270.652099, 23.034376, 0.000000, 0.000000, -30.300008, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2673, 1990.378051, -1270.699340, 23.034376, 0.000000, 0.000000, -30.300008, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2671, 1992.979003, -1268.986694, 22.994375, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2671, 2006.557006, -1277.021972, 22.820312, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2671, 1982.859375, -1279.121459, 22.820312, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2671, 2021.138671, -1286.329467, 22.943693, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2671, 2027.306640, -1280.864013, 19.987573, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2671, 2033.204833, -1304.541870, 19.917146, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1432, 2009.411743, -1282.569091, 23.100166, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1432, 1992.021728, -1282.569091, 23.100166, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1432, 1987.091064, -1284.109985, 27.460132, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1432, 2002.142089, -1284.109985, 27.460132, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1430, 2036.091796, -1279.636840, 20.272157, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2673, 2034.533691, -1279.161132, 19.973670, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2673, 2030.944091, -1288.523681, 20.030235, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2671, 2025.682983, -1303.695678, 19.903444, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 

	//Playa Del Seville
	tmpobjid = CreateDynamicObject(17951, 2727.844482, -2004.460693, 14.207196, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17508, "barrio1_lae2", "gangshop10_LAe", 0x00000000);
	tmpobjid = CreateDynamicObject(17951, 2733.984375, -2004.460693, 14.207196, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4001, "civic03_lan", "downtshop2_LAn", 0x00000000);
	tmpobjid = CreateDynamicObject(17951, 2740.146484, -2004.460693, 14.207196, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4682, "dtbuil1_lan2", "barbershop_256", 0x00000000);
	tmpobjid = CreateDynamicObject(17951, 2747.117431, -2004.453857, 14.207196, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4001, "civic03_lan", "downtshop5_LAn", 0x00000000);
	tmpobjid = CreateDynamicObject(17951, 2753.260986, -2004.473876, 14.207196, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4004, "civic07_lan", "downtshop9_LAn", 0x00000000);
	tmpobjid = CreateDynamicObject(17951, 2759.363281, -2004.463867, 14.207196, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4001, "civic03_lan", "sl_shopshttr1", 0x00000000);
	tmpobjid = CreateDynamicObject(19377, 2729.329833, -2004.563232, 12.547199, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5444, "chicano10_lae", "newall7", 0x00000000);
	tmpobjid = CreateDynamicObject(19377, 2738.991210, -2004.563232, 12.547199, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5444, "chicano10_lae", "newall7", 0x00000000);
	tmpobjid = CreateDynamicObject(19377, 2748.693359, -2004.563232, 12.547199, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5444, "chicano10_lae", "newall7", 0x00000000);
	tmpobjid = CreateDynamicObject(19377, 2758.123046, -2004.563232, 12.547199, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5444, "chicano10_lae", "newall7", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, 2747.542480, -2014.012695, 15.174691, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5114, "beach_las2", "ganggraf04_LA", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, 2735.143554, -2014.012695, 15.174691, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5390, "glenpark7_lae", "ganggraf01_LA", 0x00000000);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateDynamicObject(994, 2757.313720, -1999.890991, 12.378758, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(994, 2748.772705, -1999.890991, 12.378758, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(994, 2740.672363, -1999.890991, 12.378758, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(994, 2732.281982, -1999.890991, 12.378758, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(994, 2724.317382, -1999.890991, 12.378758, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1280, 2751.871337, -2000.216430, 12.904695, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1280, 2743.708496, -2000.216430, 12.904695, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1280, 2735.354248, -2000.216430, 12.904695, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2597, 2749.814208, -2004.098876, 13.404686, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1428, 2757.065917, -2003.985473, 14.054676, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2673, 2760.800781, -2001.650634, 12.614688, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2673, 2738.915283, -2002.214111, 12.644690, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1347, 2757.861816, -2000.349243, 13.074687, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(926, 2758.721435, -2000.330810, 12.804693, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2621, 2743.588623, -2003.928588, 13.287197, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(18639, 2750.081542, -2004.008422, 13.114693, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(18968, 2749.577148, -2004.056518, 14.161084, 0.000000, -20.899997, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(3819, 2771.050292, -2032.122924, 13.374704, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(3819, 2792.598876, -2032.122924, 13.374704, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(3594, 2759.282714, -2023.604858, 13.021964, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1331, 2728.190673, -2014.528564, 13.334692, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1331, 2741.152587, -2014.528564, 13.334692, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1331, 2755.244628, -2014.528564, 13.334692, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2673, 2750.488281, -2015.901733, 12.554687, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2673, 2736.515380, -2015.524291, 12.554687, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2671, 2730.559814, -2015.260742, 12.554687, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2671, 2721.984375, -2006.432128, 12.554687, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1223, 2756.146484, -1999.912353, 12.365779, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1223, 2739.556640, -1999.912353, 12.365779, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 

	//East Los Santos
	tmpobjid = CreateDynamicObject(3646, 2508.547851, -1525.310791, 25.319976, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(3649, 2527.021972, -1525.313232, 25.289970, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1408, 2500.022216, -1514.374633, 23.540008, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1408, 2512.938476, -1514.374633, 23.540008, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1408, 2521.883544, -1514.374633, 23.540008, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1440, 2514.951904, -1523.226562, 23.294260, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1408, 2531.773925, -1514.374633, 23.540008, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1344, 2512.937255, -1513.675781, 23.730001, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2673, 2511.656982, -1513.324218, 23.070001, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1478, 2510.401855, -1514.574218, 23.429992, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1478, 2529.200683, -1514.574218, 23.429992, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1328, 2529.699218, -1513.657348, 23.286119, 0.000000, 90.000000, 157.600006, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2671, 2530.174560, -1513.883300, 23.005315, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1264, 2514.402343, -1513.738769, 23.270006, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1291, 2519.941162, -1513.846069, 23.469999, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(926, 2520.754882, -1513.857910, 23.220005, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2673, 2521.803466, -1513.010131, 23.100002, 0.000000, 0.000000, -45.799987, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(947, 2501.467773, -1539.203735, 24.764944, 0.000000, 0.000000, -91.400016, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1280, 2509.642089, -1533.402221, 23.037645, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1280, 2527.136718, -1533.402221, 22.927642, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1438, 2519.646484, -1531.334594, 22.492366, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1264, 2514.678466, -1529.351928, 23.019002, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(947, 2513.109619, -1539.487915, 24.724943, 0.000000, 0.000000, 88.599983, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19831, 2525.161132, -1538.414306, 22.444177, 0.000000, 0.000000, 157.000045, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1810, 2527.523681, -1537.586791, 22.447584, 0.000000, 0.000000, -57.299983, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1810, 2525.883544, -1536.288330, 22.447584, 0.000000, 0.000000, 3.100012, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1810, 2527.492187, -1536.201660, 22.447584, 0.000000, 0.000000, 3.100012, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2671, 2525.918701, -1536.932617, 22.513988, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2671, 2516.727050, -1533.124877, 22.593458, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2673, 2519.899169, -1524.054931, 22.905250, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(926, 2500.066650, -1513.770263, 23.230005, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1543, 2501.114990, -1513.919433, 22.979999, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1543, 2500.664550, -1513.919433, 22.979999, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1543, 2501.355224, -1513.509033, 22.979999, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2673, 2502.943359, -1518.175415, 23.022439, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(615, 2568.243652, -1502.426391, 21.971950, 0.000000, 0.000000, 10.199992, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19447, 2580.949218, -1489.590332, 22.476642, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 

}

InsertSidejobsMaps()
{
	//Sweeper
	tmpobjid = CreateDynamicObject(2885, 867.798522, -1372.656250, 18.703805, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1411, 867.265014, -1361.797241, 14.045589, 0.000000, 0.000000, 90.800064, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1411, 868.697570, -1366.755249, 14.045589, 0.000000, 0.000000, 121.499687, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(19449, 862.923889, -1384.937622, 11.563425, 0.000000, 0.000000, 810.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1344, 864.829345, -1359.710327, 13.544247, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 
	tmpobjid = CreateDynamicObject(1344, 856.589111, -1359.710327, 13.544247, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.0, 300.0); 

	//bus
	tmpobjid = CreateDynamicObject(1257, 1651.918701, -1515.620727, 13.782821, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1257, 1796.872192, -1617.904907, 13.751561, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1257, 1858.136474, -1432.045288, 13.812816, 0.000000, 0.000000, 360.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1257, 1997.610351, -1267.116455, 24.230308, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1257, 2219.084228, -1307.088867, 24.192363, 0.000000, 0.000000, -90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1257, 2314.937744, -1390.665527, 24.186128, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1257, 2420.998535, -1262.690429, 24.222953, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1257, 2444.707031, -1420.294067, 24.208139, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1257, 2591.246093, -1450.379028, 34.426258, -4.000003, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1257, 2636.451171, -1789.685424, 11.078748, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1257, 2763.266845, -1958.252563, 13.725609, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1257, 2707.915039, -2033.329711, 13.734593, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1257, 2343.422851, -2042.893310, 13.755009, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1257, 2223.036132, -1924.873413, 13.751170, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1257, 2128.010253, -1888.050659, 13.712183, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1257, 2092.683593, -1775.880493, 13.822823, 0.000000, 0.000000, -14.600003, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1257, 1892.759155, -1745.955200, 13.732813, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1257, 1704.974487, -1726.011230, 13.762809, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1257, 1436.043823, -1697.307250, 13.692811, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1257, 1460.643798, -1458.631103, 13.772495, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1257, 1581.841918, -1447.111328, 13.760602, 0.000000, 0.000000, -90.000000, -1, -1, -1, 300.00, 300.00); 
}