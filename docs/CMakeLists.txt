find_package(Doxygen REQUIRED)
find_package(Sphinx REQUIRED)

set(AUTHOR "Anon")
string(TIMESTAMP COPYRIGHT_YEAR "%Y" UTC)

add_doxygen_docs(Doxygen_apep
  DOXYFILE_IN "Doxygen/Doxyfile.in"
  DOXYFILE_OUT "Doxygen/Doxyfile"
  GENERATE_XML GENERATE_MAN JAVADOC_BANNER
  TARGETS apep_genetic)

add_sphinx_docs(Sphinx_apep
  CONF_IN "sphinx/conf.py.in"
  CONF_OUT "sphinx/conf.py"
  RESTRUCTRED_TEXT "sphinx/index.rst"
  BREATHE_DOMAIN_ALL_CPP)
  

add_dependencies(Sphinx_apep Doxygen_apep)
