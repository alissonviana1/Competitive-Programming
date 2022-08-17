void rec(int item, int disp)
{
    if(item == q || disp == 0) return;
    if (disp - peso[item] >= 0)
    {
		 if(valor[item] + mochila(item + 1, disp - peso[item]) > mochila(item+1, disp))
		 {
			 res.push_back(peso[item]);
			 rec(item+1, disp - peso[item]);
			 return;
		 }
    }
    rec(item+1, disp);
}