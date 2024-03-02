@echo off
cd /d "%~dp0docs"
doxygen Doxyfile
cd ..
