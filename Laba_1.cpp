#include <iostream>
using namespace std;



class raft
{public:
	int universe[101];
	int u_size = 101;
	int left_range_f;
	int right_range_f;
	int left_range_s;
	int right_range_s;
	int left_range_t;
	int right_range_t;
	int* first_raft;
	int* second_raft;
	int* third_raft;
	int* new_raft;
	int new_size;
	int f_size = 0;
	int s_size = 0;
	int t_size=0;
	int left_limit = -50;
	int right_limit = 50;
	friend void Create_universe();
	raft()
	{
		
		for (int i = 0; i < u_size; i++)
		{
			universe[i] = left_limit;
			left_limit++;
			cout << universe[i] << " ";
			
		}
		cout <<endl<<  universe[u_size-1];
		first_raft = new int[f_size];
		second_raft = new int[s_size];
		third_raft = new int[t_size];
	}

	raft(int left_range_f, int right_range_f, int left_range_s, int right_range_s, int left_range_t, int right_range_t)
	{
		
		for (int i = 0; i <= u_size; i++, left_limit++)
		{
			universe[i] = left_limit;
			
		}
		if (left_range_f < -50 or right_range_f>50 or left_range_s < -50 or right_range_s>50 or left_range_t < -50 or right_range_t>50)
		{
			cout << "Не соблюдены границы универсума (от -50 до 50)" << endl;
			abort();
		}
		f_size = right_range_f - left_range_f;
		s_size = right_range_s - left_range_s;
		t_size = right_range_t - left_range_t;
		if (f_size <= 0 or s_size <= 0 or t_size<=0)
		{
			cout << "Размер множества не может быть нулевым или отрицательным";
		}
		else
		{
			first_raft = new int[f_size];
			second_raft = new int[s_size];
			third_raft = new int[t_size];
			for (int i = 0; i <= f_size; i++)
			{
				first_raft[i] = left_range_f;
				left_range_f++;
				cout << " " << first_raft[i];
			}
			cout << endl;
			for (int i = 0; i <= s_size; i++)
			{
				second_raft[i] = left_range_s;
				left_range_s++;
				cout << " " << second_raft[i];
			}
			cout << endl;
			for (int i = 0; i <= t_size; i++)
			{
				third_raft[i] = left_range_t;
				left_range_t++;
				cout << " " << third_raft[i];
			}
			cout << endl;
		}

	}

	 void array_en(int f_tmp_l,int s_tmp_l,int t_tmp_l)
	{
		 f_size = f_tmp_l;
		 s_size = s_tmp_l;
		 t_size = t_tmp_l;
		cout << "заполним первое множество: ";
		for (int i = 0; i < f_size; i++)
		{
			cin>>first_raft[i];
		}
		cout << endl << "заполним второе множество: ";
		for (int i = 0; i < s_size; i++)
		{
			cin >> second_raft[i];
		}
		cout << endl<<"заполним третье множество: ";
		for (int i = 0; i < t_size; i++)
		{
			cin >> third_raft[i];
		}
		cout << endl;

	}
		
	

	void intersection(int second_raft[], int third_raft[], int s_size, int t_size)
	{

		int counter = 0;
		cout << "s_size - " << s_size <<endl<< " t_size - " << t_size<<endl;
		if (s_size >= t_size)
		{
			new_raft = new int[t_size];
			bool flag;
			for (int j = 0, k = 0; j <= t_size; j++)
			{
				for (int i = 0; i <= s_size; i++)
					if (third_raft[j] == second_raft[i])
					{
						flag = true;
						for (int l = 0; l <= k; l++)
						{
							if (new_raft[l] == third_raft[j])
							{
								flag = false;
							}
						}
						if (flag)
						{
							
								new_raft[k++] = third_raft[j];

								cout << new_raft[j] << " ";
								counter++;
						}
						

					}
			}
		}
		else if(s_size<t_size)
		{
			new_raft = new int[s_size];
			bool flag;
			for (int j = 0, k = 0; j <= s_size; j++)
			{
				for (int i = 0; i <= t_size; i++)
					if (second_raft[j] == third_raft[i])
					{
						flag = true;
						for (int l = 0; l <= k; l++)
						{
							if (new_raft[l] == second_raft[j])
							{
								flag = false;
							}
						}
						if (flag)
						{

							new_raft[k++] = second_raft[j];
							cout << new_raft[j] << " ";
							counter++;
						}

					}
			}
		}
		new_size = counter;


	}


	void intersection_2(int tmp_first_raft[], int tmp_second_raft[], int tmp_f_size, int tmp_s_size)
	{
		int counter=-1;
		if (f_size >= s_size)
		{
			new_raft = new int[f_size];
			bool flag;
			for (int j = 0, k = 0; j <= f_size; j++)
			{
				for (int i = 0; i <= f_size; i++)
					if (second_raft[j] == first_raft[i])
					{
						flag = true;
						for (int l = 0; l <= k; l++)
						{
							if (new_raft[l] == second_raft[j])
							{
								flag = false;
							}
						}
						if (flag)
						{

							new_raft[k++] =second_raft[j];

							cout << new_raft[j] << " ";
							counter++;
							
						}


					}
			}
		}
		else if (t_size < s_size)
		{
			new_raft = new int[s_size];
			bool flag;
			for (int j = 0, k = 0; j <= s_size; j++)
			{
				for (int i = 0; i <= s_size; i++)
					if (first_raft[j] == second_raft[i])
					{
						flag = true;
						for (int l = 0; l <= k; l++)
						{
							if (new_raft[l] == first_raft[j])
							{
								flag = false;
							}
						}
						if (flag)
						{

							new_raft[k++] = first_raft[j];
							cout << new_raft[j] << " ";
							new_size = sizeof(new_raft);
							cout << endl << "размер - " << new_size;
							counter++;
						}

					}
			}
		}
	
		cout << endl<<"--------------------"<<endl;
		
		s_size = counter;
		
		cout << s_size <<endl;
		for (int i = 0; i <= s_size; i++)
		{
			second_raft[i] = new_raft[i];
			cout << second_raft[i] << "  ";
		}
		
	}


	void Union(int tmp_first_raft[], int tmp_second_raft[], int tmp_f_size, int tmp_s_size)
	{
		int i = 0;
		int j = 0;
		int k = 0;
		int counter=0;
		int* C = new int[tmp_f_size + tmp_f_size];
		
		while (i < tmp_f_size || j < tmp_s_size)
		{
			int v = 0;
			if (i < tmp_f_size && j < tmp_s_size)
			{
				v = (tmp_first_raft[i] < tmp_second_raft[j]) ? tmp_first_raft[i++] : tmp_second_raft[j++];
			}
			else
			{
				v = (tmp_f_size == i) ? tmp_second_raft[j++] : tmp_first_raft[i++];
			}
			if (k >0 && C[k-1] == v)
				continue;
			C[k++] = v;
			counter++;
			
		}
		if (tmp_first_raft[tmp_f_size] >= tmp_second_raft[tmp_s_size])
		{
			C[counter] = tmp_first_raft[tmp_f_size];
		}
		else
		{
			C[counter] = tmp_second_raft[tmp_s_size];
		}
		int c_size =1+ abs(C[0])+abs(C[counter]);
		cout << "РАЗМЕР - " << c_size<<endl;
		cout << C[0] << "      " << C[counter]<<endl;
		int tmp= C[0];
		s_size = c_size;
		second_raft[s_size];
		
		for (int i = 0; i < c_size; i++,tmp++)
		{

			second_raft[i] = tmp;
			cout << second_raft[i] << " ";
		}
		
		
		
	}

	void additional(int tmp_first_raft[], int tmp_second_raft[], int tmp_f_size, int tmp_s_size)
	{

		int i = 0;
		int j = 0;
		int k = 0;
		int counter = 0;
		int* C = new int[tmp_f_size + tmp_f_size];

		while (i < tmp_f_size || j < tmp_s_size)
		{
			int v = 0;
			if (i < tmp_f_size && j < tmp_s_size)
			{
				v = (tmp_first_raft[i] < tmp_second_raft[j]) ? tmp_first_raft[i++] : tmp_second_raft[j++];
			}
			else
			{
				v = (tmp_f_size == i) ? tmp_second_raft[j++] : tmp_first_raft[i++];
			}
			if (k > 0 && C[k - 1] == v)
				continue;
			C[k++] = v;
			counter++;

		}
		if (tmp_first_raft[tmp_f_size] >= tmp_second_raft[tmp_s_size])
		{
			C[counter] = tmp_first_raft[tmp_f_size];
		}
		else
		{
			C[counter] = tmp_second_raft[tmp_s_size];
		}
		int c_size = 1 + abs(C[0]) + abs(C[counter]);
		cout << "РАЗМЕР - " << c_size << endl;
		cout << C[0] << "      " << C[counter] << endl;
		/*
		int tmp = C[0];
		s_size = c_size;
		second_raft[s_size];

		for (int i = 0; i < c_size; i++, tmp++)
		{

			second_raft[i] = tmp;
			cout << second_raft[i] << " ";
		}
		*/
		cout << endl;
		int branch = 0;
		int cyclecount = 0;
		int left_range_tmp = C[0];
		int right_range_tmp = C[counter];
		int jump = abs(right_range_tmp) + abs(left_range_tmp);
		left_limit = -50;
		cout << "JUMP IS " << jump << endl;
		s_size = 100-jump;
		cout <<endl<< "размер - " << s_size << endl;
		second_raft[s_size];
		int sendcount = 0;
		for (int p = 0; p < s_size; p++)
		{
			second_raft[p] = left_limit;
			
			
			if ((left_limit >= left_range_tmp)&&(branch==0))
			{
					left_limit = left_limit + jump+1;
					
					branch++;
					for (int i = sendcount; i < s_size; i++)
					{
						second_raft[i] = left_limit;
						cout << second_raft[i] << " ";
						left_limit++;
						  
					}
					break;
					
			}
			left_limit++;
			cout << second_raft[p] << " ";	
			sendcount++;
		}
		
	}

	void differenceAfromB(int first_raft[], int second_raft[], int f_size, int s_size)
	{

		int counter = -1;
		if (f_size >= s_size)
		{
			new_raft = new int[f_size];
			bool flag;
			for (int j = 0, k = 0; j <= f_size; j++)
			{
				for (int i = 0; i <= f_size; i++)
					if (second_raft[j] == first_raft[i])
					{
						flag = true;
						for (int l = 0; l <= k; l++)
						{
							if (new_raft[l] == second_raft[j])
							{
								flag = false;
							}
						}
						if (flag)
						{

							new_raft[k++] = second_raft[j];

							cout << new_raft[j] << " ";
							counter++;
						}


					}
			}
		}
		else if (f_size < s_size)
		{
			new_raft = new int[s_size];
			bool flag;
			for (int j = 0, k = 0; j <= s_size; j++)
			{
				for (int i = 0; i <=s_size; i++)
					if (first_raft[j] == second_raft[i])
					{
						flag = true;
						for (int l = 0; l <= k; l++)
						{
							if (new_raft[l] == first_raft[j])
							{
								flag = false;
							}
						}
						if (flag)
						{

							new_raft[k++] = first_raft[j];
							cout << new_raft[j] << " ";
							counter++;
						}

					}
			}
		}
		new_size = counter;
		if (first_raft[0] < second_raft[0])
		{
			s_size =abs(first_raft[0]) - abs(new_raft[0]);
			
			int left_range_tmp = first_raft[0];
			cout << endl << "S_SIZE:  " << s_size << endl;
			for (int h = 0; h < s_size; h++, left_range_tmp++)
			{
				second_raft[h] = left_range_tmp;
				cout << second_raft[h] << "  ";
			}
		}
		else if (first_raft[0] >= second_raft[0])
		{
			s_size =1+ abs(second_raft[0]) - abs(new_raft[0]);
			int left_range_tmp = second_raft[0];
			cout << endl << "S_SIZE:  " << s_size << endl;
			for (int h = 0; h < s_size; h++, left_range_tmp++)
			{
				second_raft[h] = left_range_tmp;
				cout << second_raft[h] << "  ";
			}
		}

	}

	void differenceBfromA(int first_raft[], int second_raft[], int f_size, int s_size)
	{

		int counter = -1;
		if (f_size >= s_size)
		{
			new_raft = new int[f_size];
			bool flag;
			for (int j = 0, k = 0; j <= f_size; j++)
			{
				for (int i = 0; i <= f_size; i++)
					if (second_raft[j] == first_raft[i])
					{
						flag = true;
						for (int l = 0; l <= k; l++)
						{
							if (new_raft[l] == second_raft[j])
							{
								flag = false;
							}
						}
						if (flag)
						{

							new_raft[k++] = second_raft[j];

							cout << new_raft[j] << " ";
							counter++;
						}


					}
			}
		}
		else if (f_size < s_size)
		{
			new_raft = new int[s_size];
			bool flag;
			for (int j = 0, k = 0; j <= s_size; j++)
			{
				for (int i = 0; i <= s_size; i++)
					if (first_raft[j] == second_raft[i])
					{
						flag = true;
						for (int l = 0; l <= k; l++)
						{
							if (new_raft[l] == first_raft[j])
							{
								flag = false;
							}
						}
						if (flag)
						{

							new_raft[k++] = first_raft[j];
							cout << new_raft[j] << " ";
							counter++;
						}

					}
			}
		}
		new_size = counter;
		if (first_raft[f_size] < second_raft[s_size])
		{
			s_size = abs(second_raft[s_size]) - abs(new_raft[new_size]);
			int right_range_tmp = new_raft[new_size];
			cout << endl << "S_SIZE:  " << s_size << endl;
			for (int h = 0; h <= s_size; h++, right_range_tmp++)
			{
				second_raft[h] = right_range_tmp;
				cout << second_raft[h] << "  ";
			}
		}
		else if (first_raft[f_size] >= second_raft[f_size])
		{
			s_size = abs(first_raft[f_size]) - abs(new_raft[new_size]);
			int right_range_tmp = new_raft[new_size];
			cout << endl << "S_SIZE:  " << s_size << endl;
			for (int h = 0; h <= s_size; h++, right_range_tmp++)
			{
				second_raft[h] = right_range_tmp;
				cout << second_raft[h] << "  ";
			}
		}

	}

	void branch_1_fRaft(int parity)
	{
		f_size = u_size / 2;
		first_raft[f_size];
		left_limit = -50;
		if (parity == 2)
		{
			for (int i = 0; i <= f_size ; i++)
			{
					first_raft[i] = left_limit;
					cout << first_raft[i] << " ";
					left_limit += 2;

			}
		}
		if (parity == 1)
		{
			for (int i = 0; i < f_size; i++)
			{
				
					first_raft[i] = left_limit+1;
					cout << first_raft[i] << " ";
					left_limit+=2;
				
			}
		}
	}

	void branch_2_fRaft(int parity)
	{
		left_limit = -50;
		s_size = u_size / 2;
		second_raft[s_size];
		if (parity == 2)
		{
			for (int i = 0; i <= s_size; i++)
			{
				
					second_raft[i] = left_limit;
					cout << second_raft[i] << " ";
					left_limit += 2;
			}
		}
		if (parity == 1)
		{
			for (int i = 0; i < s_size; i++)
			{

					second_raft[i] = left_limit+1;
					cout << second_raft[i] << " ";
					left_limit += 2;
			}
		}
	}

	void branch_3_fRaft(int parity)
	{
		left_limit = -50;
		t_size = u_size / 2;
		third_raft[t_size];
		if (parity == 2)
		{
			for (int i = 0; i <= t_size; i++)
			{

				third_raft[i] = left_limit;
				cout << third_raft[i] << " ";
				left_limit += 2;
			}
		}
		if (parity == 1)
		{
			for (int i = 0; i < t_size; i++)
			{

				third_raft[i] = left_limit + 1;
				cout << third_raft[i] << " ";
				left_limit += 2;
			}
		}
	}

	void branch_1_sRaft(int side)
	{
		left_limit = -50;
		f_size = u_size / 2;
		first_raft[f_size];
		if (side == 1)
		{
			for (int i = 0; i < f_size; i++)
			{

				first_raft[i] = left_limit;
				cout << first_raft[i] << " ";
				left_limit ++;
			}
		}
		if (side == 2)
		{
			for (int i = 0; i < f_size; i++)
			{

				first_raft[i] = i+1;
				cout << first_raft[i] << " ";
				
			}
		}
	}

	void branch_2_sRaft(int side)
	{
		left_limit = -50;
		s_size = u_size / 2;
		second_raft[s_size];
		if (side == 1)
		{
			for (int i = 0; i < s_size; i++)
			{

				second_raft[i] = left_limit;
				cout << second_raft[i] << " ";
				left_limit++;
			}
		}
		if (side == 2)
		{
			for (int i = 0; i < s_size; i++)
			{

				second_raft[i] = i + 1;
				cout << second_raft[i] << " ";

			}
		}
	}

	void branch_3_sRaft(int side)
	{
		left_limit = -50;
		t_size = u_size / 2;
		third_raft[t_size];
		if (side == 1)
		{
			for (int i = 0; i < t_size; i++)
			{

				third_raft[i] = left_limit;
				cout << third_raft[i] << " ";
				left_limit++;
			}
		}
		if (side == 2)
		{
			for (int i = 0; i < t_size; i++)
			{

				third_raft[i] = i + 1;
				cout << third_raft[i] << " ";

			}
		}
	}
};


int main()
{
	setlocale(LC_ALL, "rus");

	/*

	int n = 0;
	int operation = 0;
	int branch_1 = 0;
	int branch_2 = 0;
	int branch_3 = 0;
	int f_tmp_l, f_tmp_r, s_tmp_l, s_tmp_r, t_tmp_l, t_tmp_r;
	cout << "каким способом зададим множества?) " << endl << "1 - Диапозоном, 2 - Перечислением, 3 - Условием" << endl;
	cin >> n;
	cout << endl;
	if (n == 1)
	{
		cout << "левая граница первого множества: ";
		cin >> f_tmp_l;
		cout << endl << "правая граница первого множества: ";
		cin >> f_tmp_r;
		cout << endl << "левая граница второго множества: ";
		cin >> s_tmp_l;
		cout << endl << "правая граница второго множества: ";
		cin >> s_tmp_r;
		cout << endl << "левая граница третьего множества: ";
		cin >> t_tmp_l;
		cout << endl << "правая граница третьего множества: ";
		cin >> t_tmp_r;
		cout << endl;
		raft a(f_tmp_l, f_tmp_r, s_tmp_l, s_tmp_r, t_tmp_l, t_tmp_r);
		int choose = 0;
		cout << "1-объединение" << endl << "2-пересечение" << endl << "3-дополнение" << endl << "4-разность A-B" << endl << "5-разность B-A" << endl;
		cin >> choose;
		if (choose == 1)
		{
			a.Union(a.first_raft, a.second_raft, a.f_size, a.s_size);

			cout << "повторим?)" << endl;
			cin >> choose;
			if (choose == 1)
			{
				a.Union(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 2)
			{
				a.intersection(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 3)
			{
				a.additional(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 4)
			{
				a.differenceAfromB(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 5)
			{
				a.differenceBfromA(a.second_raft, a.third_raft, a.s_size, a.t_size);

			}

		}
		if (choose == 2)
		{
			a.intersection_2(a.first_raft, a.second_raft, a.f_size, a.s_size);

			cout << "повторим?)" << endl;
			cin >> choose;
			if (choose == 1)
			{
				a.Union(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 2)
			{
				a.intersection(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 3)
			{
				a.additional(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 4)
			{
				a.differenceAfromB(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 5)
			{
				a.differenceBfromA(a.second_raft, a.third_raft, a.s_size, a.t_size);

			}


		}
		if (choose == 3)
		{
			a.additional(a.first_raft, a.second_raft, a.f_size, a.s_size);

			cout << "повторим?)" << endl;
			cin >> choose;
			if (choose == 1)
			{
				a.Union(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 2)
			{
				a.intersection(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 3)
			{
				a.additional(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 4)
			{
				a.differenceAfromB(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 5)
			{
				a.differenceBfromA(a.second_raft, a.third_raft, a.s_size, a.t_size);

			}

		}
		if (choose == 4)
		{
			a.differenceAfromB(a.first_raft, a.second_raft, a.f_size, a.s_size);

			cout << "повторим?)" << endl;
			cin >> choose;
			if (choose == 1)
			{
				a.Union(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 2)
			{
				a.intersection(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 3)
			{
				a.additional(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 4)
			{
				a.differenceAfromB(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 5)
			{
				a.differenceBfromA(a.second_raft, a.third_raft, a.s_size, a.t_size);

			}

		}
		if (choose == 5)
		{
			a.differenceBfromA(a.first_raft, a.second_raft, a.f_size, a.s_size);



			cout << "повторим?)" << endl;
			cin >> choose;
			if (choose == 1)
			{
				a.Union(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 2)
			{
				a.intersection(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 3)
			{
				a.additional(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 4)
			{
				a.differenceAfromB(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 5)
			{
				a.differenceBfromA(a.second_raft, a.third_raft, a.s_size, a.t_size);

			}

		}

	}

	if (n == 2)
	{
		cout << "размер первого множества: ";
		cin >> f_tmp_l;
		cout << endl << "размер второго множества: ";
		cin >> s_tmp_l;
		cout << endl << "размер третьего множества: ";
		cin >> t_tmp_l;
		cout << endl;
		raft a;
		a.array_en(f_tmp_l, s_tmp_l, t_tmp_l);
		int choose = 0;
		cout << "1-объединение" << endl << "2-пересечение" << endl << "3-дополнение" << endl << "4-разность A-B" << endl << "5-разность B-A" << endl;
		cin >> choose;
		if (choose == 1)
		{
			a.Union(a.first_raft, a.second_raft, a.f_size, a.s_size);

			cout << "повторим?)" << endl;
			cin >> choose;
			if (choose == 1)
			{
				a.Union(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 2)
			{
				a.intersection(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 3)
			{
				a.additional(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 4)
			{
				a.differenceAfromB(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 5)
			{
				a.differenceBfromA(a.second_raft, a.third_raft, a.s_size, a.t_size);

			}

		}
		if (choose == 2)
		{
			a.intersection_2(a.first_raft, a.second_raft, a.f_size, a.s_size);

			cout << "повторим?)" << endl;
			cin >> choose;
			if (choose == 1)
			{
				a.Union(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 2)
			{
				a.intersection(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 3)
			{
				a.additional(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 4)
			{
				a.differenceAfromB(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 5)
			{
				a.differenceBfromA(a.second_raft, a.third_raft, a.s_size, a.t_size);

			}


		}
		if (choose == 3)
		{
			a.additional(a.first_raft, a.second_raft, a.f_size, a.s_size);

			cout << "повторим?)" << endl;
			cin >> choose;
			if (choose == 1)
			{
				a.Union(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 2)
			{
				a.intersection(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 3)
			{
				a.additional(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 4)
			{
				a.differenceAfromB(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 5)
			{
				a.differenceBfromA(a.second_raft, a.third_raft, a.s_size, a.t_size);

			}

		}
		if (choose == 4)
		{
			a.differenceAfromB(a.first_raft, a.second_raft, a.f_size, a.s_size);

			cout << "повторим?)" << endl;
			cin >> choose;
			if (choose == 1)
			{
				a.Union(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 2)
			{
				a.intersection(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 3)
			{
				a.additional(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 4)
			{
				a.differenceAfromB(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 5)
			{
				a.differenceBfromA(a.second_raft, a.third_raft, a.s_size, a.t_size);

			}

		}
		if (choose == 5)
		{
			a.differenceBfromA(a.first_raft, a.second_raft, a.f_size, a.s_size);



			cout << "повторим?)" << endl;
			cin >> choose;
			if (choose == 1)
			{
				a.Union(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 2)
			{
				a.intersection(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 3)
			{
				a.additional(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 4)
			{
				a.differenceAfromB(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 5)
			{
				a.differenceBfromA(a.second_raft, a.third_raft, a.s_size, a.t_size);

			}

		}
	}


	if (n == 3)
	{
		raft a;

		cout << endl << "выберите вид условия для каждого множества: " << endl << "1. Четность/нечетность;2. Только положительные или отрицательные значения" << endl;
		cin >> branch_1;
		cin >> branch_2;
		cin >> branch_3;
		if (branch_1 == 1)
		{
			int parity = 0;
			cout << endl << "1 - нечетность, 2 - четность";
			cin >> parity;
			a.branch_1_fRaft(parity);
		}
		if (branch_2 == 1)
		{
			int parity = 0;
			cout << endl << "1 - нечетность, 2 - четность";
			cin >> parity;
			a.branch_2_fRaft(parity);
		}
		if (branch_3 == 1)
		{
			int parity = 0;
			cout << endl << "1 - нечетность, 2 - четность";
			cin >> parity;
			a.branch_3_fRaft(parity);

		}
		if (branch_1 == 2)
		{
			int side = 0;
			cout << endl << "1 - отрицательные числа, 2 - положительные числа";
			cin >> side;
			a.branch_1_sRaft(side);
		}
		if (branch_2 == 2)
		{
			int side = 0;
			cout << endl << "1 - отрицательные числа, 2 - положительные числа";
			cin >> side;
			a.branch_2_sRaft(side);
		}
		if (branch_3 == 2)
		{
			int side = 0;
			cout << endl << "1 - отрицательные числа, 2 - положительные числа";
			cin >> side;
			a.branch_2_sRaft(side);
		}
		int choose = 0;
		cout << "1-объединение" << endl << "2-пересечение" << endl << "3-дополнение" << endl << "4-разность A-B" << endl << "5-разность B-A" << endl;
		cin >> choose;
		if (choose == 1)
		{
			a.Union(a.first_raft, a.second_raft, a.f_size, a.s_size);

			cout << "повторим?)" << endl;
			cin >> choose;
			if (choose == 1)
			{
				a.Union(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 2)
			{
				a.intersection(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 3)
			{
				a.additional(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 4)
			{
				a.differenceAfromB(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 5)
			{
				a.differenceBfromA(a.second_raft, a.third_raft, a.s_size, a.t_size);

			}

		}
		if (choose == 2)
		{
			a.intersection_2(a.first_raft, a.second_raft, a.f_size, a.s_size);

			cout << "повторим?)" << endl;
			cin >> choose;
			if (choose == 1)
			{
				a.Union(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 2)
			{
				a.intersection(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 3)
			{
				a.additional(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 4)
			{
				a.differenceAfromB(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 5)
			{
				a.differenceBfromA(a.second_raft, a.third_raft, a.s_size, a.t_size);

			}


		}
		if (choose == 3)
		{
			a.additional(a.first_raft, a.second_raft, a.f_size, a.s_size);

			cout << "повторим?)" << endl;
			cin >> choose;
			if (choose == 1)
			{
				a.Union(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 2)
			{
				a.intersection(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 3)
			{
				a.additional(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 4)
			{
				a.differenceAfromB(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 5)
			{
				a.differenceBfromA(a.second_raft, a.third_raft, a.s_size, a.t_size);

			}

		}
		if (choose == 4)
		{
			a.differenceAfromB(a.first_raft, a.second_raft, a.f_size, a.s_size);

			cout << "повторим?)" << endl;
			cin >> choose;
			if (choose == 1)
			{
				a.Union(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 2)
			{
				a.intersection(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 3)
			{
				a.additional(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 4)
			{
				a.differenceAfromB(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 5)
			{
				a.differenceBfromA(a.second_raft, a.third_raft, a.s_size, a.t_size);

			}

		}
		if (choose == 5)
		{
			a.differenceBfromA(a.first_raft, a.second_raft, a.f_size, a.s_size);



			cout << "повторим?)" << endl;
			cin >> choose;
			if (choose == 1)
			{
				a.Union(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 2)
			{
				a.intersection(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 3)
			{
				a.additional(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 4)
			{
				a.differenceAfromB(a.second_raft, a.third_raft, a.s_size, a.t_size);
			}
			if (choose == 5)
			{
				a.differenceBfromA(a.second_raft, a.third_raft, a.s_size, a.t_size);

			}

		}
	}

	*/
	


raft a(-19, 3, -5, 27, -5, 39);
a.Union(a.first_raft, a.second_raft, a.f_size, a.s_size);
a.intersection(a.second_raft, a.third_raft, a.s_size, a.t_size);
//a.additional(a.second_raft, a.third_raft, a.s_size, a.t_size);

/*	raft a(-19, 3, -5, 27, -5, 39);
	//a.differenceBfromA(a.first_raft, a.second_raft, a.f_size, a.s_size);
	//a.Union(a.first_raft, a.second_raft, a.f_size, a.s_size);
	//a.intersection_2(a.first_raft,a.second_raft, a.f_size,a.s_size);
	//a.additional(a.first_raft, a.second_raft, a.f_size, a.s_size);
	
	cout <<endl<< a.s_size<<endl;
	for (int i = 0; i <= a.s_size; i++)
	{
		cout << a.second_raft[i] << "  ";
	}
	
	a.differenceAfromB(a.first_raft, a.second_raft, a.f_size, a.s_size);
	cout<<endl << "ENDLINE ---------" << endl;
	a.intersection(a.second_raft, a.third_raft, a.s_size, a.t_size);
	//a.Union(a.second_raft, a.third_raft, a.s_size, a.t_size);
	a.additional(a.second_raft, a.third_raft, a.s_size, a.t_size);
	*/
}

