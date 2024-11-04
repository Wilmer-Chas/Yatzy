yatzy implementation

basic game flow:
roll, choose dice to reroll x2
choose a rule to apply and cross it out
if no rule can be applied, choose a rule to cross out


so based on this i see two basic datastructures: a rule and a roll
- a roll consists of five dice, that one's pretty simple
- a rule, on the other hand, can be implemented in any number of ways.
it could be implemented as a struct with a bool to mark
whether or not it's crossed and a score value along with
separate functions to check validity. 
It could  also be implemented as a class which contains both the struct
and the function.