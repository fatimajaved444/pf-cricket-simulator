#include<iostream>
#include <cstdlib>
#include <ctime>
#include<fstream>
#include<string>
using namespace std;
void scorecard(int r[], int b[], int f[], int s[], float sr[])//scorecard of teamA
{
	char teamA[7][20] = { "Babar","Rizwan","Fakhar","Shadab","Shaheen","Zaman","Haris" };
	cout << "Team A: " << endl;
	cout << "BATTTING\t\t\tR\tB\t4s\t6s\tSR" << endl;
	cout << "-------\t\t\t\t-\t-\t--\t--\t--" << endl;
	for (int i = 0; i < 7; i++)//printing the score card
	{
		cout << teamA[i] << "\t\t\t\t" << r[i] << "\t" << b[i] << "\t" << f[i] << "\t" << s[i] << "\t" << sr[i] << "\t" << endl;
	}
	cout << "Did not bat: ";//batters who did not bat
	for (int i = 0; i < 7; i++)
	{
		if (r[i] == 0 && b[i] == 0)
		{
			cout << teamA[i] << " ";
		}
	}
	cout << endl;
}
void ballingcard2(int o[], int m[], int r[], int w[], float eco[])//balling card of team B
{
	char teamB[7][20] = { "Rahul","Rohit","Kohli","Hardik","Ashwin","Shami","chahal" };
	cout << "Bowling " << endl;
	cout << "Team B: " << endl;
	cout << "BOWLING\t\t\tO\tM\tR\tW\tECON" << endl;
	cout << "-------\t\t\t-\t-\t--\t--\t--" << endl;
	for (int i = 6; i >= 3; i--)//printing the ballingcard
	{
		cout << teamB[i] << "\t\t\t" << o[i] << "\t" << m[i] << "\t" << r[i] << "\t" << w[i] << "\t" << eco[i] << "\t" << endl;
	}
}
void scorecard2(int r[], int b[], int f[], int s[], float sr[])//scorecard of team B
{
	char teamB[7][20] = { "Rahul","Rohit","Kohli","Hardik","Ashwin","Shami","chahal" };
	cout << "Team B: " << endl;
	cout << "BATTTING\t\t\tR\tB\t4s\t6s\tSR" << endl;
	cout << "-------\t\t\t\t-\t-\t--\t--\t--" << endl;
	for (int i = 0; i < 7; i++)//printing the scorecard
	{
		cout << teamB[i] << "\t\t\t\t" << r[i] << "\t" << b[i] << "\t" << f[i] << "\t" << s[i] << "\t" << sr[i] << "\t" << endl;
	}
	cout << "Did not bat: ";//Batters that did not bat
	for (int i = 0; i < 7; i++)
	{
		if (r[i] == 0 && b[i] == 0)
		{
			cout << teamB[i] << " ";
		}
	}
	cout << endl;
}
void ballingcard(int o[], int m[], int r[], int w[], float eco[])//balling card of teamA
{
	char teamA[7][20] = { "Babar","Rizwan","Fakhar","Shadab","Shaheen","Zaman","Haris" };
	cout << "Bowling " << endl;
	cout << "Team A: " << endl;
	cout << "BOWLING\t\t\tO\tM\tR\tW\tECON" << endl;
	cout << "-------\t\t\t-\t-\t--\t--\t--" << endl;
	for (int i = 6; i >= 3; i--)//printing the balling card
	{
		cout << teamA[i] << "\t\t\t" << o[i] << "\t" << m[i] << "\t" << r[i] << "\t" << w[i] << "\t" << eco[i] << "\t" << endl;
	}
}
void file()//opening and printing the text from file
{
	fstream file;
	/*file.open("jav.txt", ios::out);
	if (file.is_open())
	{
		file << "overs= 2";
		file.close();
	}*/
	file.open("jav.txt", ios::in);//extracting the context from file
	if (file.is_open())
	{
		string line;
		while (getline(file, line))//getting the complete line from the file
		{
			cout << line << endl;//printing the line in our output
		}
		file.close();
	}
}
int readfromfile()//taking the number of overs 
{
	ifstream file;
	int a;
	char arr[50];//character array to seperate all the other wrds exepct the number we want to extract
	file.open("jav.txt");
	file >> arr;
	file >> a;//extracting the number
	file.close();
	return a;
}
void teams()//printing the teams 
{
	char teamA[7][20] = { "Babar","Rizwan","Fakhar","Shadab","Shaheen","Zaman","Haris" };
	char teamB[7][20] = { "Rahul","Rohit","Kohli","Hardik","Ashwin","Shami","chahal" };
	cout << "Team A: \t\t\t\t Team B:" << endl;
	for (int i = 0; i < 7; i++)//printing the teams side by side
	{
		cout << "Player " << i + 1 << " of team A : " << teamA[i] << "\t\t";
		cout << " Player " << i + 1 << " of team B : " << teamB[i] << endl << endl;
	}
}
int toss()//tossing for the match
{
	srand(time(0));
	int t = rand() % 2;//randomizing the toss
	int tw;
	if (t == 0)//winning condition for team A
	{
		cout << "Team A wins the toss and will bat first " << endl;
		tw = 0;
	}
	else//winning condition for team B
	{
		cout << "Team B wins the toss and will bat first " << endl;
		tw = 1;
	}
	return tw;//returning the winner of toss
}
void economy(int overs[], int runs[], float econ[])//calculating the economy
{
	for (int i = 0; i < 7; i++)//economy of each bowler
	{
		if (runs[i] == 0 || overs[i] == 0)//condition if he did not bowl any ball
		{
			econ[i] = 0.00;
		}
		else//calculation of economy
		{
			econ[i] = (float(runs[i]) / overs[i]);
		}
	}
}
void strikerate(int scores[], int balls[], float sr[])//calculating the strike rate
{
	for (int i = 0; i < 7; i++)//economy of each batter
	{
		if (balls[i] == 0)//condition if he did not face any ball
		{
			sr[i] = 0.00;
		}
		else//calculation of strikerate
		{
			sr[i] = (float(scores[i]) / balls[i]) * 100;
		}
	}
}
void bestbatter(int r[], char team[][20])//batter of the match
{
	int max = -1;//initializing with the minimum score
	int best = -1;
	for (int i = 0; i < 7; i++)
	{
		if (r[i] > max)
		{
			max = r[i];
			best = i;
		}
	}
	cout << "Batter of the match is : " << team[best] << endl;
}
void bestbowler(int f[], char team[][20], int ov[], int r[])
{
	int max_wickets = -1;
	int min_economy = INT_MAX;
	int best_bowler = -1;

	for (int i = 3; i < 7; i++)
	{
		if (ov[i] >= 1)//checking if the bowler did bowl any over or not
		{
			float economy = (float)r[i] / ov[i];//calculating economy 
			if (f[i] > max_wickets || (f[i] == max_wickets && economy < min_economy))//maaximum wickets and minimum economy condition
			{
				max_wickets = f[i];
				min_economy = economy;
				best_bowler = i;//giving the best_bowler the index from the team
			}
		}
	}

	cout << "Bowler of the match is: " << team[best_bowler] << endl;//outputting the best bowler
}
void fallofwickets(int w[7][2], int b[7][2], char team[][20], int wicket)
{
	cout << "fall of wickets: " << endl;
	if (wicket >= 1)
	{
		for (int k = 0; k < 7; k++)
		{
			if (b[k][0] != 0 && w[k][0] != 0);
			{
				cout << w[k][0] << " - " << w[k][1] << "( " << team[k] << " , " << b[k][0] << " . " << b[k][1] << " ov) " << endl;
			}
		}
	}
	else
	{
		cout << "none of the batter got out! " << endl;
	}
}
void TeamB()//if team B wins the toss
{
	int over;
	string key;
	over = readfromfile();//taken from file
	//initialization
	char teamA[7][20] = { "Babar","Rizwan","Fakhar","Shadab","Shaheen","Zaman","Haris" };
	char teamB[7][20] = { "Rahul","Rohit","Kohli","Hardik","Ashwin","Shami","chahal" };
	int scores[7] = { 0 }, balls[7] = { 0 }, fours[7] = { 0 }, sixes[7] = { 0 };
	int runs[7] = { 0 }, wickets[7] = { 0 }, maidens[7] = { 0 }, overs[7] = { 0 };
	float econ[7] = { 0.00 }, sr[7] = { 0.00 }, runrate = 0;
	int ball_over[7][2] = { 0 };
	int wicket_score[7][2] = { 0 };
	int total = 0, toatalwickets = 0, bowler = 6, b1 = 0, b2 = 1;
	int i = 1;
	bool allout = false;//allout condition
	cout << "\t\t\tInnings 1" << endl << endl;
	cout << "Team B batting" << endl;
	while (i <= over && !allout)//loop for the overs and allout flag in it
	{
		cout << "Over: " << i << endl << endl;
		for (int j = 1; j <= 6; j++)//loop for the balls of the over
		{
			cout << "Batters are: " << endl;//printing the batter
			cout << teamB[b1] << " And " << teamB[b2] << endl;
			cout << "Bowler is: " << teamA[bowler] << endl;//printing the bowler
			cout << "Bowl number " << j << " : " << endl;
			cout << "Press enter to bowl: ";
			getline(cin, key);
			while (key != "")
			{
				cout << "Invalid input plz press enter key!!" << endl;
				getline(cin, key);
			}
			if (key == "")
			{
				int score;
				//calculating the probability of scoring or getting out for the batsmen 
				if (b1 < 4)//batters less than index 4
				{
					score = rand() % 10 == 0 ? -1 : rand() % 7;
				}
				else//baters Aftr index 4
				{
					score = rand() % 2 == 0 ? -1 : rand() % 7;
				}
				total += score;
				if (score == -1)//condition for getting out for the batter
				{
					total += 1;
					cout << "Out!" << endl;
					toatalwickets += 1;
					wickets[bowler] += 1;
					balls[b1] += 1;
					ball_over[b1][0] = i - 1;
					ball_over[b1][1] = j;
					wicket_score[b1][0] = toatalwickets;
					wicket_score[b1][1] = total;
					//getting new batter on crease
					if (b1 < b2)
					{
						b1 = b2;
						b1 = (b1 + 1) % 7;
					}
					else
					{
						b1 = (b1 + 1) % 7;
					}
					if (toatalwickets == 6)//if all out 
					{
						allout = true;
						break;
					}
				}
				else
				{
					scores[b1] += score;
					runs[bowler] += score;
					balls[b1] += 1;
					//if batsman hits four
					if (score == 4)
					{
						fours[b1] += 1;
					}
					//if hits 6
					else if (score == 6)
					{
						sixes[b1] += 1;
					}
					cout << "Score is : " << score << endl;
					cout << teamB[b1] << " scored " << scores[b1] << " runs in " << balls[b1] << " balls with " << fours[b1] << " fours and " << sixes[b1] << " sixes" << endl;
					//changing the strike
					if (score % 2 == 1)
					{
						swap(b1, b2);
					}
					//live scorecard after each ball
					cout << "----------------------------------------------------------------" << endl;
					cout << "LIVE SCOREBOARD: \n";
					cout << "----------------------------------------------------------------" << endl;
					cout << "SCORE\t\tSTRIKER\t\tNON-STRIKER\t\tBOWLER\n";
					cout << "----------------------------------------------------------------" << endl;
					cout << total << " - " << toatalwickets << "\t\t" << teamB[b1] << "\t\t" << teamB[b2] << "\t\t\t" << teamA[bowler] << endl;
					cout << "----------------------------------------------------------------" << endl;
					cout << i - 1 << " . " << j << "\t\t" << scores[b1] << "(" << balls[b1] << ")\t\t" << scores[b2] << "(" << balls[b2] << ")\t\t\t" << runs[bowler] << "-" << wickets[bowler] << endl;
					cout << "----------------------------------------------------------------" << endl;
					strikerate(scores, balls, sr);
				}
			}
		}
		//changing the strike
		swap(b1, b2);
		if (runs[bowler] == 0)//calculating the maiden overs
		{
			maidens[bowler] += 1;
		}
		overs[bowler] += 1;
		scorecard2(scores, balls, fours, sixes, sr);
		runrate = float(total) / i;//runrate calculation
		cout << "TOTAL: \t" << i << " OVRS(RR: " << runrate << ")\t" << total << "/" << toatalwickets << endl;
		economy(overs, runs, econ);
		ballingcard(overs, maidens, runs, wickets, econ);
		bowler--;
		if (bowler < 3)//repeating the bowler
		{
			bowler = 6;
		}
		i++;
	}
	//fall of wickets
	fallofwickets(wicket_score, ball_over, teamB, toatalwickets);
	cout << "Target is : " << total << " in " << over << " overs " << endl;
	cout << endl;
	cout << "\t\t\tInnings 2" << endl << endl;
	cout << "Team A batting " << endl;
	//again initializing for second innings
	int total1 = 0, c1 = 0, c2 = 1, bowler1 = 6;
	int scores1[7] = { 0 }, balls1[7] = { 0 }, fours1[7] = { 0 }, sixes1[7] = { 0 };
	int runs1[7] = { 0 }, wickets1[7] = { 0 }, maidens1[7] = { 0 }, overs1[7] = { 0 };
	float econ1[7] = { 0.00 }, sr1[7] = { 0.00 }, runrate1 = 0;
	int toatalwickets1 = 0;
	int ball_over1[7][2] = { 0 };
	int wicket_score1[7][2] = { 0 };
	int i1 = 1;
	bool allout1 = false;
	bool chase = false;
	while (i1 <= over && !allout1 && !chase)//loop for overs
	{
		cout << "Over: " << i1 << endl << endl;
		for (int j = 1; j <= 6; j++)//loop for balls
		{
			cout << "Batters are: " << endl;//printing the second inning batter
			cout << teamA[c1] << " And " << teamA[c2] << endl;
			cout << "Bowler is: " << teamB[bowler1] << endl;//printing the second team bowler
			cout << "Bowl number " << j << " : " << endl;
			cout << "Press enter to bowl: ";
			getline(cin, key);
			while (key != "")
			{
				cout << "Invalid input plz press enter key!!" << endl;
				getline(cin, key);
			}
			if (key == "")
			{
				int score;
				//calculating the probability of scoring or getting out for the batsmen 
				if (c1 < 4)
				{
					score = rand() % 10 == 0 ? -1 : rand() % 7;
				}
				else
				{
					score = rand() % 2 == 0 ? -1 : rand() % 7;
				}
				total1 += score;
				if (score == -1)//condition for getting out for the batter
				{
					total1 += 1;
					cout << "Out!" << endl;
					toatalwickets1 += 1;
					wickets1[bowler1] += 1;
					balls1[c1] += 1;
					ball_over1[c1][0] = i1 - 1;
					ball_over1[c1][1] = j;
					wicket_score1[c1][0] = toatalwickets1;
					wicket_score1[c1][1] = total1;
					if (c1 < c2)
					{
						c1 = c2;
						c1 = (c1 + 1) % 7;
					}
					else
					{
						c1 = (c1 + 1) % 7;
					}
					if (toatalwickets1 == 6)//allout condition
					{
						allout1 = true;
						break;
					}
				}
				else
				{
					scores1[c1] += score;
					runs1[bowler1] += score;
					balls1[c1] += 1;
					if (score == 4)//counting 4
					{
						fours1[c1] += 1;
					}
					else if (score == 6)//counting 6
					{
						sixes1[c1] += 1;
					}
					cout << "Score is : " << score << endl;
					cout << teamA[c1] << " scored " << scores1[c1] << " runs in " << balls1[c1] << " balls with " << fours1[c1] << " fours and " << sixes1[c1] << " sixes" << endl;
					if (score % 2 == 1)//strike rotation
					{
						swap(c1, c2);
					}
					//live scorecard after each ball
					cout << "-----------------------------------------------------------------" << endl;
					cout << "LIVE SCOREBOARD: \n";
					cout << "-----------------------------------------------------------------" << endl;
					cout << "SCORE\t\tSTRIKER\t\tNON-STRIKER\t\tBOWLER\n";
					cout << "-----------------------------------------------------------------" << endl;
					cout << total1 << " - " << toatalwickets1 << "\t\t" << teamA[c1] << "\t\t" << teamA[c2] << "\t\t\t" << teamB[bowler1] << endl;
					cout << "-----------------------------------------------------------------" << endl;
					cout << i1 - 1 << " . " << j << "\t\t" << scores1[c1] << "(" << balls1[c1] << ")\t\t" << scores1[c2] << "(" << balls1[c2] << ")\t\t\t" << runs1[bowler1] << "-" << wickets1[bowler1] << endl;
					cout << "-----------------------------------------------------------------" << endl;
					strikerate(scores1, balls1, sr1);
				}
				if (total1 > total)//chasing condition 
				{
					chase = true;
					break;
				}
			}

		}
		swap(c1, c2);//strike rotation
		if (runs1[bowler1] == 0)//maiden calculation
		{
			maidens1[bowler1] += 1;
		}
		overs1[bowler1] += 1;
		scorecard(scores1, balls1, fours1, sixes1, sr1);

		cout << "Remaining Overs: " << over - i1 << endl;//remaining overs
		if (total1 <= total)
		{
			cout << "Remaining Score: " << total - total1 << endl;
		}
		else//if score is chased no need to play for more over
		{
			cout << "Score chased!!!!" << endl;
			runrate1 = float(total1) / i1;
			cout << "TOTAL: \t" << i1 << " OVRS(RR: " << runrate1 << ")\t" << total1 << "/" << toatalwickets1 << endl;
			economy(overs1, runs1, econ1);
			ballingcard2(overs1, maidens1, runs1, wickets1, econ1);
			break;
		}
		runrate1 = float(total1) / i1;//calculating runrate
		cout << "TOTAL: \t" << i1 << " OVRS(RR: " << runrate1 << ")\t" << total1 << "/" << toatalwickets1 << endl;
		economy(overs1, runs1, econ1);
		ballingcard2(overs1, maidens1, runs1, wickets1, econ1);
		bowler1--;
		if (bowler1 < 3)//repeating ballers
		{
			bowler1 = 6;
		}
		i1++;
	}
	//fall of wickets
	fallofwickets(wicket_score1, ball_over1, teamA, toatalwickets1);
	cout << endl;
	cout << "Team A's total is : " << total1 << endl << "Team B's total is: " << total << endl;
	if (total > total1)//match winner,best batter,bowler
	{
		cout << "Team B has won the match!!!" << endl << endl;
		bestbatter(scores, teamB);
		cout << endl;
		bestbowler(wickets1, teamB, overs1, runs1);
	}
	else if (total < total1)//match winner,best batter,bowler
	{
		cout << "Team A has won the match!!!" << endl << endl;
		bestbatter(scores1, teamA);
		cout << endl;
		bestbowler(wickets, teamA, overs, runs);
	}
	else
	{
		cout << "Match drawn: " << endl << endl;
	}
	fstream file;
	file.open("Summary.txt", ios::out);//putting the match summary in file
	if (file.is_open())
	{
		file << "Team A's total is : " << total1 << endl << "Team B's total is: " << total << endl << endl;
		if (total > total1)//match winner,best batter,bowler
		{
			file << "Team B has won the match!!!" << endl << endl;
		}
		else if (total < total1)//match winner,best batter,bowler
		{
			file << "Team A has won the match!!!" << endl << endl;
		}
		else
		{
			file << "Match drawn: " << endl << endl;
		}
		file << endl;
		file << "Team A: " << endl;
		file << "BATTTING\tR \tB \t4s \t6s \tSR" << endl;
		file << "--------\t--\t--\t--\t--\t--" << endl;
		for (int i = 0; i < 7; i++)
		{
			file << teamA[i] << "   \t" << scores1[i] << " \t" << balls1[i] << " \t" << fours1[i] << " \t" << sixes1[i] << " \t" << sr1[i] << " \t" << endl;
		}
		file << "Did not bat: ";
		for (int i = 0; i < 7; i++)
		{
			if (scores1[i] == 0 && balls1[i] == 0)
			{
				file << teamA[i] << " ";
			}
		}
		file << endl << endl;
		file << "Team B: " << endl;
		file << "BATTTING\tR \tB \t4s \t6s \tSR" << endl;
		file << "--------\t--\t--\t--\t--\t--" << endl;
		for (int i = 0; i < 7; i++)
		{
			file << teamB[i] << "   \t" << scores[i] << " \t" << balls[i] << " \t" << fours[i] << " \t" << sixes[i] << " \t" << sr[i] << " \t" << endl;
		}
		file << "Did not bat: ";
		for (int i = 0; i < 7; i++)
		{
			if (scores[i] == 0 && balls[i] == 0)
			{
				file << teamB[i] << " ";
			}
		}
		file << endl << endl;
		file << "Team A: " << endl;
		file << "BOWLING  \tO \tM \tR \tW \tECON" << endl;
		file << "--------\t--\t--\t--\t--\t--" << endl;
		for (int i = 6; i >= 3; i--)
		{
			file << teamA[i] << "   \t" << overs[i] << " \t" << maidens[i] << " \t" << runs[i] << " \t" << wickets[i] << " \t" << econ[i] << " \t" << endl;
		}
		file << endl << endl;
		file << "Team B: " << endl;
		file << "BOWLING  \tO \tM \tR \tW \tECON" << endl;
		file << "--------\t--\t--\t--\t--\t--" << endl;
		for (int i = 6; i >= 3; i--)
		{
			file << teamB[i] << "   \t" << overs1[i] << " \t" << maidens1[i] << " \t" << runs1[i] << " \t" << wickets1[i] << " \t" << econ1[i] << " \t" << endl;
		}
	}
}
void TeamA()//if team A wins the toss
{
	int over;
	string key;
	over = readfromfile();//if team A
	//initialization
	char teamA[7][20] = { "Babar","Rizwan","Fakhar","Shadab","Shaheen","Zaman","Haris" };
	char teamB[7][20] = { "Rahul","Rohit","Kohli","Hardik","Ashwin","Shami","chahal" };
	int scores[7] = { 0 }, balls[7] = { 0 }, fours[7] = { 0 }, sixes[7] = { 0 };
	int runs[7] = { 0 }, wickets[7] = { 0 }, maidens[7] = { 0 }, overs[7] = { 0 };
	float econ[7] = { 0.00 }, sr[7] = { 0.00 }, runrate = 0;
	int ball_over[7][2] = { 0 };
	int wicket_score[7][2] = { 0 };
	int total = 0, toatalwickets = 0, bowler = 6, b1 = 0, b2 = 1;
	int i = 1;
	bool allout1 = false;
	cout << "\t\t\tInnings 1" << endl << endl;
	cout << "Team A batting" << endl;
	while (i <= over && !allout1)//loop for the overs
	{
		cout << "Over: " << i << endl << endl;
		for (int j = 1; j <= 6; j++)//loop for the balls of the over
		{
			cout << "Batters are: " << endl;
			cout << teamA[b1] << " And " << teamA[b2] << endl;
			cout << "Bowler is : " << endl << teamB[bowler] << endl;
			cout << "Bowl number " << j << " : " << endl;
			cout << "Press enter to bowl: ";
			getline(cin, key);
			while (key != "")
			{
				cout << "Invalid input plz press enter key!!" << endl;
				getline(cin, key);
			}
			if (key == "")
			{
				int score;
				//calculating the probability of scoring or getting out for the batsmen
				if (b1 < 4)
				{
					score = rand() % 10 == 0 ? -1 : rand() % 7;
				}
				else
				{
					score = rand() % 2 == 0 ? -1 : rand() % 7;
				}
				total += score;
				if (score == -1)//condition for getting out for the batter
				{
					total += 1;
					cout << "Out!" << endl;
					toatalwickets += 1;
					wickets[bowler] += 1;
					balls[b1] += 1;
					ball_over[b1][0] = i - 1;
					ball_over[b1][1] = j;
					wicket_score[b1][0] = toatalwickets;
					wicket_score[b1][1] = total;
					if (b1 < b2)//getting new batter on crease
					{
						b1 = b2;
						b1 = (b1 + 1) % 7;
					}
					else
					{
						b1 = (b1 + 1) % 7;
					}
					if (toatalwickets == 6)
					{
						allout1 = true;
						break;

					}
				}
				else
				{
					scores[b1] += score;
					runs[bowler] += score;
					balls[b1] += 1;
					if (score == 4)//if batsman hits four
					{
						fours[b1] += 1;
					}
					else if (score == 6)	//if hits 6
					{
						sixes[b1] += 1;
					}
					cout << "Score is : " << score << endl;
					cout << teamA[b1] << " scored " << scores[b1] << " runs in " << balls[b1] << " balls with " << fours[b1] << " fours and " << sixes[b1] << " sixes" << endl;
					if (score % 2 == 1)//changing the strike
					{
						swap(b1, b2);
					}
					//live scorecard after each ball
					cout << "----------------------------------------------------------------" << endl;
					cout << "LIVE SCOREBOARD: \n";
					cout << "----------------------------------------------------------------" << endl;
					cout << "SCORE\t\tSTRIKER\t\tNON-STRIKER\t\tBOWLER" << endl;
					cout << "----------------------------------------------------------------" << endl;
					cout << total << " - " << toatalwickets << "\t\t" << teamA[b1] << "\t\t" << teamA[b2] << "\t\t\t" << teamB[bowler] << endl;
					cout << "----------------------------------------------------------------" << endl;
					cout << i - 1 << " . " << j << "\t\t" << scores[b1] << "(" << balls[b1] << ")\t\t" << scores[b2] << "(" << balls[b2] << ")\t\t\t" << runs[bowler] << "-" << wickets[bowler] << endl;
					cout << "----------------------------------------------------------------" << endl;
					strikerate(scores, balls, sr);
				}
			}
		}
		swap(b1, b2);	//changing the strike
		if (runs[bowler] == 0)//calculating the maiden overs
		{
			maidens[bowler] += 1;
		}
		overs[bowler] += 1;
		scorecard(scores, balls, fours, sixes, sr);
		runrate = float(total) / i;//runrate calculation
		cout << "TOTAL: \t" << i << " OVRS(RR: " << runrate << ")\t" << total << "/" << toatalwickets << endl;
		economy(overs, runs, econ);
		ballingcard2(overs, maidens, runs, wickets, econ);
		bowler--;
		if (bowler < 3)//repeating the bowler
		{
			bowler = 6;
		}
		i++;
	}
	//fall of wickets
	fallofwickets(wicket_score, ball_over, teamA, toatalwickets);
	cout << "Target is : " << total << " in " << over << " overs " << endl << endl;
	cout << "\t\t\tInnings 2" << endl << endl;
	cout << "Team B batting: " << endl << endl;
	//again initializing for second innings
	int total1 = 0, c1 = 0, c2 = 1, bowler1 = 6;
	int scores1[7] = { 0 }, balls1[7] = { 0 }, fours1[7] = { 0 }, sixes1[7] = { 0 };
	int runs1[7] = { 0 }, wickets1[7] = { 0 }, maidens1[7] = { 0 }, overs1[7] = { 0 };
	float econ1[7] = { 0.00 }, sr1[7] = { 0.00 }, runrate1 = 0;
	int toatalwickets1 = 0;
	int ball_over1[7][2] = { 0 };
	int wicket_score1[7][2] = { 0 };
	int i1 = 1;
	bool allout = false;
	bool chase = false;
	while (i1 <= over && !allout && !chase)//loop for overs
	{
		cout << "Over: " << i1 << endl << endl;
		for (int j = 1; j <= 6; j++)//loop for balls
		{
			cout << "Batters are: " << endl;
			cout << teamB[c1] << " And " << teamB[c2] << endl;
			cout << "Bowler is: " << teamA[bowler1] << endl;
			cout << "Bowl number " << j << " : " << endl;
			cout << "Press enter to bowl: ";
			getline(cin, key);
			while (key != "")
			{
				cout << "Invalid input plz press enter key!!" << endl;
				getline(cin, key);
			}
			if (key == "")
			{
				int score;
				//calculating the probability of scoring or getting out for the batsmen 
				if (c1 < 4)
				{
					score = rand() % 10 == 0 ? -1 : rand() % 7;
				}
				else
				{
					score = rand() % 2 == 0 ? -1 : rand() % 7;
				}
				total1 += score;
				if (score == -1)//condition for getting out for the batter
				{
					total1 += 1;
					cout << "Out!" << endl;
					toatalwickets1 += 1;
					wickets1[bowler1] += 1;
					balls1[c1] += 1;
					ball_over1[c1][0] = i1 - 1;
					ball_over1[c1][1] = j;
					wicket_score1[c1][0] = toatalwickets1;
					wicket_score1[c1][1] = total1;
					if (c1 < c2)
					{
						c1 = c2;
						c1 = (c1 + 1) % 7;
					}
					else
					{
						c1 = (c1 + 1) % 7;
					}
					if (toatalwickets1 == 6)
					{
						allout = true;
						break;
					}
				}
				else
				{
					scores1[c1] += score;
					runs1[bowler1] += score;
					balls1[c1] += 1;
					if (score == 4)//counting 4
					{
						fours1[c1] += 1;
					}
					else if (score == 6)//counting 6
					{
						sixes1[c1] += 1;
					}
					cout << "Score is : " << score << endl;
					cout << teamB[c1] << " scored " << scores1[c1] << " runs in " << balls1[c1] << " balls with " << fours1[c1] << " fours and " << sixes1[c1] << " sixes" << endl;
					if (score % 2 == 1)//strike rotation
					{
						swap(c1, c2);
					}
					//live scorecard after each ball
					cout << "----------------------------------------------------------------" << endl;
					cout << "LIVE SCOREBOARD: \n";
					cout << "----------------------------------------------------------------" << endl;
					cout << "SCORE\t\tSTRIKER\t\tNON-STRIKER\t\tBOWLER\n";
					cout << "----------------------------------------------------------------" << endl;
					cout << total1 << " - " << toatalwickets1 << "\t\t" << teamB[c1] << "\t\t" << teamB[c2] << "\t\t\t" << teamA[bowler1] << endl;
					cout << "----------------------------------------------------------------" << endl;
					cout << i1 - 1 << " . " << j << "\t\t" << scores1[c1] << "(" << balls1[c1] << ")\t\t" << scores1[c2] << "(" << balls1[c2] << ")\t\t\t" << runs1[bowler1] << "-" << wickets1[bowler1] << endl;
					cout << "----------------------------------------------------------------" << endl;
					strikerate(scores1, balls1, sr1);
				}
				if (total1 > total)
				{
					chase = true;
					break;
				}
			}
		}
		swap(c1, c2);//strike rotation
		if (runs1[bowler1] == 0)//maiden calculation
		{
			maidens1[bowler1] += 1;
		}
		overs1[bowler1] += 1;
		scorecard2(scores1, balls1, fours1, sixes1, sr1);
		cout << "Remaining Overs: " << over - i1 << endl;//remaining overs
		if (total1 <= total)
		{
			cout << "Remaining Score: " << total - total1 << endl;
		}
		else//if score is chased no need to play for more over
		{
			cout << "Score chased!!" << endl;
			runrate1 = float(total1) / i1;
			cout << "TOTAL: \t" << i1 << " OVRS(RR: " << runrate1 << ")\t" << total1 << "/" << toatalwickets1 << endl;
			economy(overs1, runs1, econ1);
			ballingcard(overs1, maidens1, runs1, wickets1, econ1);
			break;
		}
		runrate1 = float(total1) / i1;//calculating runrate
		cout << "TOTAL: \t" << i1 << " OVRS(RR: " << runrate1 << ")\t" << total1 << "/" << toatalwickets1 << endl;
		economy(overs1, runs1, econ1);
		ballingcard(overs1, maidens1, runs1, wickets1, econ1);
		bowler1--;
		if (bowler1 < 3)//repeating ballers
		{
			bowler1 = 6;
		}
		i1++;
	}
	//fall of wickets
	fallofwickets(wicket_score1, ball_over1, teamB, toatalwickets1);
	cout << "Team A's total is : " << total << endl << "Team B's total is: " << total1 << endl;
	if (total > total1)//match winner,best batter,bowler
	{
		cout << "Team A has won the match!!!" << endl;
		bestbatter(scores, teamA);
		bestbowler(wickets1, teamA, overs1, runs1);
	}
	else if (total < total1)//match winner,best batter,bowler
	{

		cout << "Team B has won the match!!!" << endl;
		bestbatter(scores1, teamB);
		bestbowler(wickets, teamB, overs, runs);
	}
	else
	{
		cout << "Match drawn: " << endl << endl;
	}
	fstream file;
	file.open("Summary.txt", ios::out);//putting the match summary in file
	if (file.is_open())
	{
		file << "Team A's total is : " << total << endl << "Team B's total is: " << total1 << endl << endl;
		if (total > total1)//match winner,best batter,bowler
		{
			file << "Team A has won the match!!!" << endl;
		}
		else if (total < total1)//match winner,best batter,bowler
		{

			file << "Team B has won the match!!!" << endl;
		}
		else
		{
			file << "match drawn!!!";
		}
		file << endl;
		file << "Team A: " << endl;
		file << "BATTTING\tR \tB \t4s \t6s \tSR" << endl;
		file << "--------\t--\t--\t--\t--\t--" << endl;
		for (int i = 0; i < 7; i++)
		{
			file << teamA[i] << "   \t" << scores[i] << " \t" << balls[i] << " \t" << fours[i] << " \t" << sixes[i] << " \t" << sr[i] << " \t" << endl;
		}
		file << "Did not bat: ";
		for (int i = 0; i < 7; i++)
		{
			if (scores[i] == 0 && balls[i] == 0)
			{
				file << teamA[i] << " ";
			}
		}
		file << endl << endl;
		file << "Team B: " << endl;
		file << "BATTTING\tR \tB \t4s \t6s \tSR" << endl;
		file << "--------\t--\t--\t--\t--\t--" << endl;
		for (int i = 0; i < 7; i++)
		{
			file << teamB[i] << "   \t" << scores1[i] << " \t" << balls1[i] << " \t" << fours1[i] << " \t" << sixes1[i] << " \t" << sr1[i] << " \t" << endl;
		}
		file << "Did not bat: ";
		for (int i = 0; i < 7; i++)
		{
			if (scores1[i] == 0 && balls1[i] == 0)
			{
				file << teamB[i] << " ";
			}
		}
		file << endl << endl;
		file << "Team A: " << endl;
		file << "BOWLING  \tO \tM \tR \tW \tECON" << endl;
		file << "--------\t--\t--\t--\t--\t--" << endl;
		for (int i = 6; i >= 3; i--)
		{
			file << teamA[i] << "   \t" << overs1[i] << " \t" << maidens1[i] << " \t" << runs1[i] << " \t" << wickets1[i] << " \t" << econ1[i] << " \t" << endl;
		}
		file << endl << endl;
		file << "Team B: " << endl;
		file << "BOWLING  \tO \tM \tR \tW \tECON" << endl;
		file << "--------\t--\t--\t--\t--\t--" << endl;
		for (int i = 6; i >= 3; i--)
		{
			file << teamB[i] << "   \t" << overs[i] << " \t" << maidens[i] << " \t" << runs[i] << " \t" << wickets[i] << " \t" << econ[i] << " \t" << endl;
		}
	}
}
void PrintSummary()
{
	fstream file;
	file.open("Summary.txt", ios::in);
	if (file.is_open())
	{
		char temp[1000];
		while (!file.eof())
		{
			file.getline(temp, 1000);
			cout << temp;
			cout << endl;
		}
		file.close();
	}
}
int main()
{
	int n;
	string key;
	cout << "Press Enter to start the match:";
	getline(cin, key);
	while (key != "")
	{
		cout << "Invalid input plz press enter key!!" << endl;
		getline(cin, key);
	}
	if (key == "")
	{
		teams();//function to print both teams
		file();//function to print number of overs from a file
		cout << "press enter to toss:";
		getline(cin, key);
		while (key != "")
		{
			cout << "Invalid input plz press enter key!!" << endl;
			getline(cin, key);
		}
		if (key == "")
		{
			int t;
			t = toss();//function to give us the toss winner
			if (t == 0)//if teamA wins the toss
			{
				cout << endl;
				TeamA();//function to start the playing of teams with team A to bat first
			}
			else
			{
				cout << endl;
				TeamB();//function to start the playing of teams with team B to bat first
			}
			cout << endl;
			cout << "Press 1 to show summary: ";
			cin >> n;
			cout << endl;
			if (n == 1)
			{
				PrintSummary();
			}
			return 0;
		}
	}
}