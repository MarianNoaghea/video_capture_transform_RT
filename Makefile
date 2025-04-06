build:
	g++ video_transform.cpp -o video_transform `pkg-config --cflags --libs opencv4`

run:
	./video_transform

clean:
	rm video_transform