@echo off 
echo delete all pre-compiled cia's and cxi files
del *.cia
echo ready to compile the new CIA!
pause
cxitool.exe GeekShop.3dsx GeekShop.cxi
makerom.exe -f cia -o GeekShop.cia -target t -i GeekShop.cxi:0:0
del *.cxi
pause
exit