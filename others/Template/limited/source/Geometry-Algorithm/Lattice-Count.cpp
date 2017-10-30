//多边形内点计数
// rn 中的标号必须逆时针给出。一开始要旋转坐标,保证同一个 x
// 值上只有一个点。正向减点,反向加点。num[i][j]=num[j][i]=
// 严格在这根线下方的点。on[i][j]=on[j][i]=
// 严格在线段上的点,包括两个端点。若有回边的话注意计算 onit
// 的方法,不要多算了线段上的点。ans-lows+1 is inside.
// 只会多算一次正向上的点(除去最左和最右的点)。Lows
// 只算了除开最左边的点,但会多算最右边的点,所以要再加上 1.
int ans = 0, z, onit = 0, lows = 0;
rep(z, t) {
	i = rn[z];
	j = rn[z + 1];
	onit += on[i][j] - 1;
	if (a[j].x > a[i].x) {
		ans -= num[i][j];
		lows += on[i][j] - 1;
	} else
		ans += num[i][j];
}
printf("%d\n", ans - lows + 1 + onit);
