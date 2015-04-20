# invoke SourceDir generated makefile for app.pe430X
app.pe430X: .libraries,app.pe430X
.libraries,app.pe430X: package/cfg/app_pe430X.xdl
	$(MAKE) -f /home/vagrant/Desktop/dory/TIRTOSkernelExamplesMinimal/src/makefile.libs

clean::
	$(MAKE) -f /home/vagrant/Desktop/dory/TIRTOSkernelExamplesMinimal/src/makefile.libs clean

