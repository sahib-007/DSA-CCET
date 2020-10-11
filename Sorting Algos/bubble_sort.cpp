int main()
{
	int n;
	cout<<"n=";
	cin>>n;
	int a[n];
	cout<<"Enter the elements:\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int c=a[j];
				a[j]=a[j+1];
				a[j+1]=c;
			}
		}
	}
	cout<<"After sorting by bubble sort:";
	for(int i=0;i<n;i++)
	{
		cout<<endl<<a[i]<<"  ";
	}
}
