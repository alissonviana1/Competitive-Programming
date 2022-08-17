int mochila(int item, int disp)
{
	if( disp == 0 || item == q ) return 0;
	if(pd[item][disp] != -1) return pd[item][disp];
	if(disp-peso[item] < 0) return pd[item][disp] = mochila(item + 1, disp);
	return pd[item][disp] = max(mochila(item+1,disp), valor[item]+mochila(item+1,disp-peso[item]));

}