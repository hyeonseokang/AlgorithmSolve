#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>

using namespace std;

long long maxHp = 0;

class Dungeon {
public:
	virtual bool Excute(long long& playerHP, long long& playerPower) {
		return false;
	}
};

class MonsterDungeon : public Dungeon {
private:
	int power;
	int hp;

public:
	MonsterDungeon(int power, int hp) :power(power), hp(hp) {

	}

	bool Excute(long long& playerHP, long long& playerPower) override {
		long long playerDieTurn = (playerHP - 1) / power + 1;
		long long monsterDieTurn = (hp - 1) / playerPower + 1;

		if (playerDieTurn >= monsterDieTurn) {
			playerHP -= (monsterDieTurn - 1) * power;
			return true;
		}

		playerHP = 0;
		return false;
	}
};

class PotionDungeon : public Dungeon {
private:
	int powerValue;
	int hpValue;

public:
	PotionDungeon(int powerValue, int hpValue) : powerValue(powerValue), hpValue(hpValue) {

	}

	bool Excute(long long& playerHP, long long& playerPower) override {
		playerHP = min(playerHP + hpValue, maxHp);
		playerPower += powerValue;
		return true;
	}	
};

int n;
long long initAttackPower;
vector<Dungeon*> dungeons;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> initAttackPower;
	dungeons.reserve(n + 1);
	for (int i = 0; i < n; i++) {
		int t, a, h;
		cin >> t >> a >> h;

		if (t == 1) {
			dungeons.emplace_back(new MonsterDungeon(a, h));
		}
		else if (t == 2) {
			dungeons.emplace_back(new PotionDungeon(a, h));
		}
	}

	long long l = 1;
	long long r = LLONG_MAX / 2;

	while (l < r) {
		long long m = (l + r) / 2;
		maxHp = m;

		long long hp = maxHp;
		long long power = initAttackPower;
		bool isSuccess = true;
		for (int i = 0; i < n; i++) {
			isSuccess = dungeons[i]->Excute(hp, power);
			if (isSuccess == false) {
				break;
			}
		}

		if (isSuccess) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}

	cout << r << "\n";

	return 0;
}
