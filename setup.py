import setuptools
import cemake

setuptools.setup(
    ext_modules = [cemake.CMakeExtension("Extension_Package")],
    cmdclass = {'build_ext': cemake.cmake_build_ext}
    )
