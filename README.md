# Cars2D
ASCII game, Console double buffering, WinAPI, Standard Template Library, Dynamic memory allocation, Job for friend, Studies - Use of OOP

https://www.youtube.com/watch?v=b344BwRUue0 - gameplay.

It is a simple ASCII game I made for my studies mate. He consented me to publish the source. The game is pretty hard. The player has a car and he have to avoid enemies and earn as much points as possible. The more points you got the harder the game becoms. That's becouse there are more and more enemies.
I'm using here my own solution for console double buffering to avoid flickering. The ASCII drawing methods names and uses are similar to their equivalents in SFML library so it would be easy to change the game to graphic version. There are classes like TextWindow and TextSprite which works very near to sf::RenderWindow and sf:Sprite and I will maybe develop them in the future. After changing the console window size the game could flicker (Restart required). Unfortunetly on some computers (especially with Windows 7 but not ever) it doesn't work as well as I expected.
