int Maxflow_Isap(int s,int t,int n) {
	std::fill(pre + 1, pre + n + 1, 0);
	std::fill(d + 1, d + n + 1, 0);
	std::fill(gap + 1, gap + n + 1, 0);
	for (int i = 1; i <= n; i++) cur[i] = h[i];
	gap[0] = n;
	int u = pre[s] = s, v, maxflow = 0;
	while (d[s] < n) {
		v = n + 1;
		for (int i = cur[u]; i; i = e[i].next)
		if (e[i].flow && d[u] == d[e[i].node] + 1) {
			v = e[i].node; cur[u]=i; break;
		}
		if (v <= n) {
			pre[v] = u; u = v;
			if (v == t) {
				int dflow = INF, p = t; u = s;
				while (p != s) {
					p = pre[p];
					dflow = std::min(dflow, e[cur[p]].flow);
				}
				maxflow += dflow; p = t;
				while (p != s) {
					p = pre[p];
					e[cur[p]].flow -= dflow;
					e[e[cur[p]].opp].flow += dflow;
				}
			}
		}
		else{
			int mindist = n + 1;
			for (int i = h[u]; i; i = e[i].next)
				if (e[i].flow && mindist > d[e[i].node]) {
					mindist = d[e[i].node]; cur[u] = i;
				}
			if (!--gap[d[u]]) return maxflow;
			gap[d[u] = mindist + 1]++; u = pre[u];
		}
	}
	return maxflow;
}
