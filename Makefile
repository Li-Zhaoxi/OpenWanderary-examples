
rely:
	cd OpenWanderary; \
	make rely

download:
	bash data/download_models.sh;

wdr:
	cd OpenWanderary; \
	make release; \

install:
	mkdir .cache; \
	cd OpenWanderary; \
	cd build_release; \
	sudo make install; \
	sudo ldconfig; \
	pip install dist/wanderary-0.1.0-py3-none-any.whl --force-reinstall


example:
	cmake -S . -B build_release -DCMAKE_BUILD_TYPE=Release; \
	make -j6 -C build_release/;
