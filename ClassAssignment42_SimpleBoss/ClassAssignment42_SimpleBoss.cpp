#include <iostream>

class Enemy {
public:

    Enemy(int damage = 10);
    void virtual Attack() const;             //Made virtual to be overridden. Only used in declaration
    void virtual Taunt() const;
protected:                                   //Can only be accessed by derived classes
    int m_Damage;
};

Enemy::Enemy(int damage):                              //This is also called when creating a boss
    m_Damage(damage)
{
    std::cout << "\nCreating an Enemy\n";
}

void Enemy::Attack() const{
    std::cout << "Attack inflicts " << m_Damage << " damage points!\n";
}

void Enemy::Taunt() const{
    std::cout << "The enemy says, 'I will destroy you, human!'";
}

class Boss :public Enemy {                  //Creating a Boss class derived from the Enemy class
public:
    Boss(int damage = 20);
    void SpecialAttack() const;             //a member function specific to this class derivative
    void virtual Attack() const;            //Since this is the override, theres no need to declare virtual. But I do it anyway.
    void virtual Taunt() const;

private:
    int m_DamageMultiplier;
};

Boss::Boss(int damage):
    Enemy(damage),          //Calls base constructor, which is called first, with argument
    m_DamageMultiplier(3)
{
    std::cout << "\nCreating a boss\n";
}

void Boss::Taunt() const {                  //This function overrides the Enemy Taunt function
    std::cout << "The Boss exclaims, 'This will be your last dungeon, adventurer!'\n";
}

void Boss::Attack() const {
    Enemy::Attack();                        //You can call a base class function within an override function
    std::cout << "The boss reels back to unleash a strike!\n\n";
}

void Boss::SpecialAttack() const {
    std::cout << "The boss jumps in the air, landing with a powerful blow!\n";

    std::cout << "Special Attack inflicts " << (m_DamageMultiplier * m_Damage);
    std::cout << " damage points!\n";
}

int main()
{
    Enemy enemy1;
    enemy1.Attack();
    enemy1.Taunt();

    Boss boss1;
    boss1.Attack();                        //Calling attack from the Boss class, as it inherits all public class members of enemy.
    boss1.SpecialAttack();
    boss1.Taunt();

    system("pause");
}