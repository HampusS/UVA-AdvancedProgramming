// uva10078ArtGallery.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
struct Vertex {
	int x, y;
};
int cross(Vertex o, Vertex a, Vertex b) {
	return (a.x - o.x)*(b.y - o.y) -
		(a.y - o.y)*(b.x - o.x);
}
int main() {
	int n, i;
	Vertex vertices[100]{ 0 };

	while (scanf("%d", &n), n) {
		for (i = 0; i < n; i++)
			scanf("%d %d", &vertices[i].x, &vertices[i].y);

		//Enclose the graph to remove remainder null positions
		vertices[n] = vertices[0]/*, vertices[n + 1] = vertices[1]*/;

		int iniCross = cross(vertices[0], vertices[1], vertices[2]),
			currCross= cross(vertices[i], vertices[i + 1], vertices[i + 2]);

		if (iniCross >= 0) {
			for (i = 0; i < n; i++)
				if (cross(vertices[i], vertices[i + 1], vertices[i + 2]) < 0)
					break;
		}
		else {
			for (i = 0; i < n; i++)
				if (cross(vertices[i], vertices[i + 1], vertices[i + 2]) > 0)
					break;
		}
		i != n ? puts("Yes") : puts("No");
	}
	return 0;
}