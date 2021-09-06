# Authify
Authify is an advanced authentication system written to be better than the other ones publicly available with streaming of images with proper encryption instead of out-of-the-box AES with no actual security.

# Security practices
To keep authify as secure as possible, we have decided to use statically linked libraries, dynamic link libraries with exported functions and some examples without streaming of images. In this industry, we are actively fighting against reverse engineers, so staying secure is key and is more important than transparency.

# Subscriptions?
To keep authify online, we have decided to add a one-time payment of 14.99 USD for access to streaming.
Keep in mind you may get access for free if you either promote our service or help us.

# Staying secure
Now obviously if you are an experienced developer you would understand to never trust the client, we take this very seriously.

### Here is a couple of tips for staying secure. 
* Never place streamed images on disk if you wouldn't just send it to them.
* We don't encrypt user data when authenticating as it doesn't matter because even poisoning DNS is always a scenario that is where streaming comes in, it's authenticated via a session-id returned when authenticated.
* Don't trust all windows api functions, I would recommend checking some flags directly from PEB which you can get either by using intrinsic functions or just `NtCurrentTeb()->ProcessEnvironmentBlock`


# Why use us?
I know we don't have all the other features matching competitors but this is a work in progress and we write our products with best practices for each language.
Not to be a prick but if you look at [KeyAuth](https://github.com/keyauth) you would notice their code is a complete mess and written terribly not even using prepared statements.

# Information
Authify was written with:
* [NodeJS](https://nodejs.dev/)
* [MySQL](https://www.npmjs.com/package/mysql)
* [Express](https://expressjs.com/)
* [LiquidJS](https://liquidjs.com/index.html)
