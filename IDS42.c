#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int IDS (int from, int to, int limit, int depth){
	int ret = 0;
	if (from == to){
		return depth;
	}
	if (limit == 0){
		return -1;
	}
	ret = IDS (from+1, to, limit-1, depth+1);
	if (ret != 0){
		return ret;
	}
	ret = IDS (from-1, to, limit-1, depth+1);
	if (ret != 0){
		return ret;
	}
	ret = IDS (from*2, to, limit-1, depth+1);
	if (ret != 0){
		return ret;
	}
	ret = IDS (from*3, to, limit-1, depth+1);
	if (ret != 0){
		return ret;
	}
	ret = IDS (from/2, to, limit-1, depth+1);
	if (ret != 0){
		return ret;
	}
	ret = IDS (from/3, to, limit-1, depth+1);
	if (ret != 0){
		return ret;
	}
	return -1;
}

int main (int argc, char *argv[]){
	int from=0, to=0, ret=-1, limit = 1;
	printf("Please enter input; search from x to y: x y\n");
	scanf("%d %d\n", &from, &to);
	printf("From: %d to: %d", from, to);
	while (ret == -1){
		ret = IDS (from, to, limit, 0);
		limit++;
	}
	printf("So many steps are required to get from %d to %d: %d\n", from, to, ret);
	return 0;
}
