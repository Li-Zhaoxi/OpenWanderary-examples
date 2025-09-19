
rely:
	cd OpenWanderary; \
	make rely

wdr:
	cd OpenWanderary; \
	make release; \

make install-wdr:
	cd OpenWanderary; \
	cd build_release; \
	sudo make install
