
rely:
	cd OpenWanderary; \
	make rely

download:
	bash data/download_models.sh;

wdr:
	cd OpenWanderary; \
	make release; \

install-wdr:
	mkdir .cache
	cd OpenWanderary; \
	cd build_release; \
	sudo make install
	sudo ldconfig

example:
	cmake -S . -B build_release -DCMAKE_BUILD_TYPE=Release; \
	make -j6 -C build_release/;
