
// each hash is 1"x4" -- this assumes every coordinate in the array is .5"
// assumes the bottom left corner is passed in
void fill_hash(double start_x, double start_y, int &map[][]) {
	// start x + 1" is the end of the hash
	for (int x = start_x; x < start_x+2; x++) {
		// starty + 4" is the end of the hash
		for (int y = start_y; y < start_y+8; y++) {
			// this assumes the # 3 represents hashes
			map[x][y] = 3;
		}
	}
}

// center line is 1"x 65"
void fill_center(double start_x, double start_y, int &map[][]) {
	// startx + 65" is the end of the row
	for (int x = start_x; x < start_x+(65*2); x++) {
		// starty + 1" is the height of the line
		for (int y = start_y; y < start_y+(2)) {
			// this assumes the # 2 represents the center line
			map[x][y] = 2;
		}
	}
}