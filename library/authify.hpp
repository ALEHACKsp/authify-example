#pragma once

#include <iostream>
#include <vector>

namespace authify
{
	enum app_status : int
	{
		detected,
		testing,
		undetected
	};

	enum error : int
	{
		restart,
		success,
		failure
	};

	class secure_image
	{
	private:
		std::vector<std::uint32_t> image;
	public:
		authify::secure_image init(std::vector<std::uint32_t> image);

		std::vector<std::uint32_t> decrypt(std::uint32_t encryption_key);
	};

	class license
	{
	public:
		std::string id, license_key, app, expiry, hwid, created_at, session;

		license();

		license(std::string id, std::string license_key, std::string app, std::string expiry, std::string hwid, std::string created_at, std::string session);

		authify::secure_image stream();
	};


	class auth
	{
	private:
		std::string app;
	public:
		authify::auth init(std::string id);

		authify::error authenticate(std::string license, authify::license& response);
	};
}