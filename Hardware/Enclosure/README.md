# File Descriptions

## To build an enclosure print these six files.

1. [U_Box_V105_General_Alarm_Device_Backpanel.stl](U_Box_V105_General_Alarm_Device_Backpanel.stl)
2. [U_Box_V105_General_Alarm_Device_FrontPanel.stl](U_Box_V105_General_Alarm_Device_FrontPanel.stl)
3. [U_Box_V105_General_Alarm_Device_Top.stl](U_Box_V105_General_Alarm_Device_Top.stl)
4. [U_Box_V105_General_Alarm_Device_bottom.stl](U_Box_V105_General_Alarm_Device_bottom.stl)
5. [U_Box_V104_General_Alarm_Device_button.stl](U_Box_V104_General_Alarm_Device_button.stl)
6. [U_Box_V105_GPAD_LED_Standoff_single.stl](U_Box_V105_GPAD_LED_Standoff_single.stl)  Six of these for each assembly are required.
7. The file [BackPanel_Hanging-CompoundV2.stl](BackPanel_Hanging-CompoundV2.stl) is an alternate part with features to allow hanging the GPAD with tie wraps to a horizontal bar.

## Source files for generating STL files
[U_Box_V105_General_Alarm_Device.scad](U_Box_V105_General_Alarm_Device.scad)

To export the OpenSCAD, modify the scad file and toggle one of the STL elemnets on or off. 
```
/* [STL element to export] */
//Coque haut - Top shell
TShell          = 0;// [0:No, 1:Yes]
//Coque bas- Bottom shell
BShell          = 0;// [0:No, 1:Yes]
//Panneau avant - Front panel
FPanL           = 0;// [0:No, 1:Yes]
//Panneau arrière - Back panel  
BPanL           = 0;// [0:No, 1:Yes]
//Buttons
BButton         = 0;
//show pcb
PCB_View        = 0;
LED_Standoff    = 0;
LED_Standoff_Single    = 1; 
```

[BackPanel_Hanging.FCStd](Hardware/Enclosure/BackPanel_Hanging.FCStd)

### Folder(s)  
**Speaker2W**  
A tentative moving could speaker. About 1" diameter. This is a FreeCAD drawing made by measuring principle points of of a part with calipers.  Exported to PDF with mechanical dimensions. Exported to STEP and STL files.


