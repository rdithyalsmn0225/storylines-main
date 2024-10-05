enum E_PROJECT_PROPS_DATA {
    E_PROJECT_PROPS_MODEL,
    Float: E_PROJECT_PROPS_POS_X,
    Float: E_PROJECT_PROPS_POS_Y,
    Float: E_PROJECT_PROPS_POS_Z,
    Float: E_PROJECT_PROPS_ROT_X,
    Float: E_PROJECT_PROPS_ROT_Y,
    Float: E_PROJECT_PROPS_ROT_Z
};

new ProjectPropData[][E_PROJECT_PROPS_DATA] = {
    {19482, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

InsertProjectPropsData() 
{    
    new objectid = INVALID_STREAMER_ID;
    for(new i, j = sizeof(ProjectPropData); i < j; i ++) {

        objectid = CreateDynamicObject(ProjectPropData[i][E_PROJECT_PROPS_MODEL], ProjectPropData[i][E_PROJECT_PROPS_POS_X], ProjectPropData[i][E_PROJECT_PROPS_POS_Y], 
            ProjectPropData[i][E_PROJECT_PROPS_POS_Z], ProjectPropData[i][E_PROJECT_PROPS_ROT_X], ProjectPropData[i][E_PROJECT_PROPS_ROT_Y], ProjectPropData[i][E_PROJECT_PROPS_ROT_Z]);

        Streamer_SetFloatData(STREAMER_TYPE_OBJECT, objectid, E_STREAMER_STREAM_DISTANCE, 300.0);
        Streamer_SetFloatData(STREAMER_TYPE_OBJECT, objectid, E_STREAMER_DRAW_DISTANCE, 350.0);

        //CreateDynamic3DTextLabel(sprintf("Project Props\nIndex: %i (model %i)", i, ProjectPropData[i][E_PROJECT_PROPS_MODEL]), 0x42f5c2AA, ProjectPropData[i][E_PROJECT_PROPS_POS_X], ProjectPropData[i][E_PROJECT_PROPS_POS_Y], 
        //    ProjectPropData[i][E_PROJECT_PROPS_POS_Z], 12.5, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, false);
    }
}