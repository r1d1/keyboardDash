////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
/*
KEYBOARD DASH
*/

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define SPEED 1000
#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 600
//#define WINDOW_HEIGHT 200

#define EXTERNALTRACK 90
#define INTERNALTRACK 30
#define DOTSIZE 40
#define CONTOURSIZE 0

void ThreadFunction(void* UserData) //, sf::Sound & soundToPlay)
{
	std::cout << "Coucou !" << std::endl;
}

int main(int argc, char** argv)
{
	srand(time(NULL));
	float dotSpeed = 10.0;
	// ================ Initialising ! ================
	// Create main window
	// Black screen
	sf::RenderWindow App(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Keyboard Dash !!!");
	
	sf::SoundBuffer faSoundBuf;
	sf::SoundBuffer solSoundBuf;
	sf::SoundBuffer laSoundBuf;
	sf::SoundBuffer siSoundBuf;
	sf::Sound faSound;
	sf::Sound solSound;
	sf::Sound laSound;
	sf::Sound siSound;
	if( !faSoundBuf.LoadFromFile("sounds/fa.wav")){ std::cerr << "Can't load sound file " << std::endl; }
	if( !solSoundBuf.LoadFromFile("sounds/sol.wav")){ std::cerr << "Can't load sound file " << std::endl; }
	if( !laSoundBuf.LoadFromFile("sounds/la.wav")){ std::cerr << "Can't load sound file " << std::endl; }
	if( !siSoundBuf.LoadFromFile("sounds/si.wav")){ std::cerr << "Can't load sound file " << std::endl; }

	// Associate buffer to sound :
	faSound.SetBuffer(faSoundBuf);
	solSound.SetBuffer(solSoundBuf);
	laSound.SetBuffer(laSoundBuf);
	siSound.SetBuffer(siSoundBuf);
	//laSound.Play();
	//sleep(laSoundBuf.GetDuration()+1);
	
//	sf::Shape redDot = sf::Shape::Circle(WINDOW_WIDTH / 2 - EXTERNALTRACK, 20, DOTSIZE, sf::Color::Red, CONTOURSIZE, sf::Color::White);
//	sf::Shape yellowDot = sf::Shape::Circle(WINDOW_WIDTH / 2 - INTERNALTRACK, 20, DOTSIZE, sf::Color::Yellow, CONTOURSIZE, sf::Color::White);
//	sf::Shape greenDot = sf::Shape::Circle(WINDOW_WIDTH / 2 + INTERNALTRACK, 20, DOTSIZE, sf::Color::Green, CONTOURSIZE, sf::Color::White);
//	sf::Shape blueDot = sf::Shape::Circle(WINDOW_WIDTH / 2 + EXTERNALTRACK, 20, DOTSIZE, sf::Color::Blue, CONTOURSIZE, sf::Color::White);
	
	sf::Sprite redDot;
	sf::Sprite yellowDot;
	sf::Sprite greenDot;
	sf::Sprite blueDot;

	sf::Image redImage(DOTSIZE, DOTSIZE, sf::Color::Red);
	sf::Image yellowImage(DOTSIZE, DOTSIZE, sf::Color::Yellow);
	sf::Image greenImage(DOTSIZE, DOTSIZE, sf::Color::Green);
	sf::Image blueImage(DOTSIZE, DOTSIZE, sf::Color::Blue);
	sf::Image whiteImage(DOTSIZE, DOTSIZE, sf::Color::White);

	redDot.SetPosition(WINDOW_WIDTH / 2 - EXTERNALTRACK - DOTSIZE / 2 , 20);
	yellowDot.SetPosition(WINDOW_WIDTH / 2 - INTERNALTRACK - DOTSIZE / 2, 20);
	greenDot.SetPosition(WINDOW_WIDTH / 2 + INTERNALTRACK - DOTSIZE / 2, 20);
	blueDot.SetPosition(WINDOW_WIDTH / 2 + EXTERNALTRACK - DOTSIZE / 2, 20);

	for(int x=0; x < DOTSIZE ; x++)
	{
		for(int y = 0 ; y < DOTSIZE ; y++)
		{
			if( pow(x - (DOTSIZE / 2), 2) + pow(y - (DOTSIZE / 2), 2) > pow((DOTSIZE / 2),2) )
			{
				redImage.SetPixel(x, y, sf::Color::Black);
				yellowImage.SetPixel(x, y, sf::Color::Black);
				greenImage.SetPixel(x, y, sf::Color::Black);
				blueImage.SetPixel(x, y, sf::Color::Black);
				whiteImage.SetPixel(x, y, sf::Color::Black);
			}
		}
	}
 
//	redImage.SetPixel(x, y, sf::Color::Black);
	redImage.SetPixel(1, 1, sf::Color::Black);
	redImage.SetPixel(2, 2, sf::Color::Black);
	redImage.SetPixel(3, 3, sf::Color::Black);
	redImage.SetPixel(4, 4, sf::Color::Black);
	redImage.SetPixel(5, 5, sf::Color::Black);

	redDot.SetImage(redImage);
	yellowDot.SetImage(yellowImage);
	greenDot.SetImage(greenImage);
	blueDot.SetImage(blueImage);

	bool redDotPressed = false;
	bool yellowDotPressed = false;
	bool greenDotPressed = false;
	bool blueDotPressed  = false;

	// ----------------------------------------
	// Start game loop
	float cumulativeTime = 0.0;
	
	while (App.IsOpened())
	{
		// Process events
		sf::Event Event;
		float elapsedTime = App.GetFrameTime();

//		redDot.SetColor(sf::Color::Red);
//		yellowDot.SetColor(sf::Color::Yellow);
//		greenDot.SetColor(sf::Color::Green);
//		blueDot.SetColor(sf::Color::Blue);
		
		while (App.GetEvent(Event))
		{
			// Event processing
			if(Event.Type == sf::Event::Closed){ App.Close(); }
			if(Event.Type == sf::Event::KeyPressed)
			{
				if (App.GetInput().IsKeyDown(sf::Key::Escape)){ App.Close(); }
					
				if (App.GetInput().IsKeyDown(sf::Key::F1)){ redDotPressed = true; }
				if (App.GetInput().IsKeyDown(sf::Key::F2)){ yellowDotPressed = true; }
				if (App.GetInput().IsKeyDown(sf::Key::F3)){ greenDotPressed = true; }
				if (App.GetInput().IsKeyDown(sf::Key::F4)){ blueDotPressed  = true; }
				
				if (App.GetInput().IsKeyDown(sf::Key::Back)){ std::cout << "Back" << std::endl; }
				
				if (App.GetInput().IsKeyDown(sf::Key::Numpad0)){ dotSpeed += 5;  std::cout << "Speed++" << std::endl; }
				if (App.GetInput().IsKeyDown(sf::Key::Numpad1)){ dotSpeed -= 5; std::cout << "Speed--" << std::endl; }
			}
			else
			{
				redDotPressed = false;
				yellowDotPressed = false;
				greenDotPressed = false;
				blueDotPressed = false;
			}

			if( !redDotPressed ){ redDot.SetImage(redImage); } else
			{
				redDot.SetImage(whiteImage);
				sf::Thread Thread(&ThreadFunction); //, &laSound);
				    // Start it !
			        Thread.Launch();
				faSound.Play();
			}
			if( !yellowDotPressed ){ yellowDot.SetImage(yellowImage); } else
			{
				yellowDot.SetImage(whiteImage);
				solSound.Play();
			}
			if( !greenDotPressed ){ greenDot.SetImage(greenImage); } else
			{
				greenDot.SetImage(whiteImage);
				laSound.Play();
			}
			if( !blueDotPressed ){ blueDot.SetImage(blueImage); } else
			{
				blueDot.SetImage(whiteImage);
				siSound.Play();
			}
		}

		redDot.Move(0.0, dotSpeed * elapsedTime);
		yellowDot.Move(0.0, dotSpeed * elapsedTime);
		greenDot.Move(0.0, dotSpeed * elapsedTime);
		blueDot.Move(0.0, dotSpeed * elapsedTime);

		App.Clear(sf::Color::Black);

		cumulativeTime += elapsedTime;

		App.Draw(sf::Shape::Line(WINDOW_WIDTH / 2 - EXTERNALTRACK, 0, WINDOW_WIDTH / 2 - EXTERNALTRACK, WINDOW_HEIGHT, 7, sf::Color::Black, 5, sf::Color::Red)); 
		App.Draw(sf::Shape::Line(WINDOW_WIDTH / 2 - INTERNALTRACK, 0, WINDOW_WIDTH / 2 - INTERNALTRACK, WINDOW_HEIGHT, 7, sf::Color::Black, 5, sf::Color::Yellow)); 
		App.Draw(sf::Shape::Line(WINDOW_WIDTH / 2 + INTERNALTRACK, 0, WINDOW_WIDTH / 2 + INTERNALTRACK, WINDOW_HEIGHT, 7, sf::Color::Black, 5, sf::Color::Green)); 
		App.Draw(sf::Shape::Line(WINDOW_WIDTH / 2 + EXTERNALTRACK, 0, WINDOW_WIDTH / 2 + EXTERNALTRACK, WINDOW_HEIGHT, 7, sf::Color::Black, 5, sf::Color::Blue)); 
		//App.Draw(sf::Shape::Circle(10, 10, 50, sf::Color((1.0 - 0.0) * 255, 0.0 * 255, 0), 5, sf::Color::White)); 
		App.Draw(redDot);
		App.Draw(yellowDot);
		App.Draw(greenDot);
		App.Draw(blueDot);
		App.Display();
	}

	return EXIT_SUCCESS;
}

