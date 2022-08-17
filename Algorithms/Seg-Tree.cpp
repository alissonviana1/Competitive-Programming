no nil = 1;
no blah(no a,no b){ return ((a) * (b)); }

int A[100000];
no st[4*100000];

#define L (2 * t)
#define R (2 * t + 1)
#define M ((l + r) / 2)


no build(int t, int l, int r)
{
	if (l == r) return st[t] = qual(A[l]);
	int esquerda = build (L, l ,M);
	int direita =  build(R, M + 1, r);
	
	return st[t] = esquerda*direita;
}

no qry(int i, int j, int t, int l, int r)
{
	if(r < i || j < l) return nil;
	if(i <= l && r <= j) return st[t];
	int esquerda = qry(i,j,L,l,M);
	int direita = qry(i,j,R,M+1,r);
	
	return esquerda*direita;
}

no upd(int i, no x, int t, int l, int r)
{
	if(r < i || i < l) return st[t];
	if(l == r) return st[t] = qual(x);
	
	int esquerda = upd(i,x,L,l,M);
	int direita = upd(i,x,R,M+1,r);
	
	return st[t] = esquerda*direita;
}