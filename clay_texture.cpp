/**
 * @file clay_texture.cpp
 * @author Hridiza Roy (hridizaroy@gmail.com)
 * @brief This is a Maya Plugin that will give a clay-look to all meshes in a scene
 * @version 0.1
 * @date 2024-01-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <maya/MString.h>
#include <maya/MArgList.h>
#include <maya/MFnPlugin.h>
#include <maya/MPxCommand.h>
#include <maya/MIOStream.h>
#include <maya/MGlobal.h>
#include <fstream>
#include <iostream>
#include <filesystem>

class ClayTexture : public MPxCommand
{
public:
    inline static const MString commandName = "addClayTexture";

    MStatus doIt(const MArgList& args);
    static void* creator();
};

MStatus ClayTexture::doIt(const MArgList& args)
{
    std::cout << "Adding Clay Texture\n";

    // Read MEL File and execute each command in it
    std::string filename = "clay_texture.mel";

    if (!std::filesystem::exists(filename))
    {
        std::cout << "File does not exist\n";
        std::cout << "CWD: " << std::filesystem::current_path() << "\n";
    }
    else
    {
        std::ifstream melFile(filename);

        std::string line;
        while (std::getline(melFile, line))
        {
            const char* cmd = line.c_str();
            std::cout << cmd << "\n";
            MGlobal::executeCommand(cmd);
        }
    }

    return MS::kSuccess;
}

void* ClayTexture::creator()
{
    return new ClayTexture;
}

MStatus initializePlugin(MObject obj)
{
    MFnPlugin plugin(obj, "Autodesk", "1.0", "Any");
    plugin.registerCommand(ClayTexture::commandName, ClayTexture::creator);
    return MS::kSuccess;
}

MStatus uninitializePlugin(MObject obj)
{
    MFnPlugin plugin(obj);
    plugin.deregisterCommand(ClayTexture::commandName);
    return MS::kSuccess;
}