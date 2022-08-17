int troco(int item, int soma)
{
	if(soma == valor) return 1;
	if(item == n) return 0;
	if(pd[item][soma] != -1) return pd[item][soma];
	if(soma + vetor[item] <= valor)
	{
		return pd[item][soma] = troco(item+1,soma+vetor[item]) || troco(item+1,soma);
	}
	return pd[item][soma] = troco(item+1, soma);
}