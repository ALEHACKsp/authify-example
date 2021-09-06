#include <authify.hpp>
#include <string>

void authenticated(authify::license license)
{
	/*
	People could obviously patch an instruction and jump here but the actual license object has to be valid or else you will except when referencing it.
	*/

	std::cout << "Welcome user\n" << "Your license expires on " << license.expiry << std::endl;

	authify::secure_image image = license.stream(); // The actual image is still encrypted

	std::vector<std::uint32_t> decrypted_image = image.decrypt(128); // Encryption key
	for (std::uint32_t byte : decrypted_image)
	{
		std::cout << "Byte: " << std::hex << byte << std::endl;
	}
}

std::uint32_t main()
{
	authify::auth auth = authify::auth().init("APP_ID");

	std::cout << "Please enter license: ";

	std::string license;
	std::getline(std::cin, license);

	authify::license result;

	switch (auth.authenticate(license, result))
	{
	case authify::error::success:
		authenticated(result);
		break;
	case authify::error::restart:
		std::cout << "Please restart the application" << std::endl;
		break;
	case authify::error::failure:
		std::cout << "Please enter a valid license" << std::endl;
		break;
	}

	return 0;
}