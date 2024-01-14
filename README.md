## Description
This is a WIP Maya Plugin for applying different art styles to 3D Models

## Using the C++ plugin version
- Download the dist/clay_texture.mll file to your computer
- Download the clay_texture.jpg and clay_texture.mel files to the same folder where your Maya binary/executable is installed
- Open a Maya Project
- Open Plug-in manager using Windows -> Settings/Preferences -> Plug-in Manager
- Click on "Browse", select the downloaded file, and click on "Open"
- Check the "Loaded" checkbox next to this plugin
- To unload the plugin, open Plug-in Manager, uncheck the "Loaded" checkbox next to this plugin
- To add clay texture to all meshes in the scene, run the following MEL command:
```
addClayTexture;
```

## Using the Python plugin version
- Download the py2_clay_texture.py file to your computer
- Download the clay_texture.jpg and clay_texture.mel files to the same folder where your Maya binary/executable is installed
- Open a Maya Project
- Open Plug-in manager using Windows -> Settings/Preferences -> Plug-in Manager
- Click on "Browse", select the downloaded file, and click on "Open"
- Check the "Loaded" checkbox next to this plugin
- To unload the plugin, open Plug-in Manager, uncheck the "Loaded" checkbox next to this plugin
- To add clay texture to all meshes in the scene, run the following MEL command:
```
py2_add_clay_texture;
```

## Building the Project:
Follow the instructions on https://help.autodesk.com/view/MAYAUL/2022/ENU/?guid=Maya_SDK_Setting_up_your_build_html to set up your development environment and build this project

## Attributions
clay_texture.jpg: <a href="https://www.freepik.com/free-vector/blue-texture-design_938735.htm#query=clay%20surface&position=35&from_view=keyword&track=ais&uuid=f4abb5a3-8ef8-4edf-90d5-fc1ff2ab9c8d">Image by dotstudio</a> on Freepik