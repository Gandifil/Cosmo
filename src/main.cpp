#include "Info/Config.h"
#include "UI/Window.h"

int main() {
	Cosmo::UI::Window window{ Cosmo::Info::Config::Instance() };
	return window.MainLoop();
}