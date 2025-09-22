if [ "$1" == "win64" ];
then
	cd build-win64
	cmake .. -DCMAKE_TOOLCHAIN_FILE=../mingw-toolchain.cmake
	make
	if [ "$2" == "run" ];
	then
		wine Game.exe
	fi 
elif [ "$1" == "linux" ];
then
	cd build-linux
	cmake ..
	make
	if [ "$2" == "run" ];
	then
		./Game
	fi 
fi
