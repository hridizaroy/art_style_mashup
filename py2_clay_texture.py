import sys
import os
import maya.api.OpenMaya as om
import maya.mel as mel

def maya_useNewAPI():
    """
    The presence of this function tells Maya that the plugin produces, and
    expects to be passed, objects created using the Maya Python API 2.0.
    """
    pass


# command
class Py2ClayTextureCmd(om.MPxCommand):
    kPluginCmdName = "py2_add_clay_texture"

    def __init__(self):
        om.MPxCommand.__init__(self)

    @staticmethod
    def cmdCreator():
        return Py2ClayTextureCmd()

    def doIt(self, args):
        filename = "clay_texture.mel"
        if not(os.path.exists(filename)):
            print("File does not exist")
        else:
            with open(filename) as mel_file:
                for cmd in mel_file:
                    try:
                        mel.eval(cmd)
                    except:
                        pass

# Initialize the plug-in
def initializePlugin(plugin):
    pluginFn = om.MFnPlugin(plugin)
    try:
        pluginFn.registerCommand(
            Py2ClayTextureCmd.kPluginCmdName, Py2ClayTextureCmd.cmdCreator
        )
    except:
        sys.stderr.write(
            "Failed to register command: %s\n" % Py2ClayTextureCmd.kPluginCmdName
        )
    raise


# Uninitialize the plug-in
def uninitializePlugin(plugin):
    pluginFn = om.MFnPlugin(plugin)
    try:
        pluginFn.deregisterCommand(Py2ClayTextureCmd.kPluginCmdName)
    except:
        sys.stderr.write(
            "Failed to unregister command: %s\n" % Py2ClayTextureCmd.kPluginCmdName
        )
    raise