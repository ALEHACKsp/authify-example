# Example
This just includes a simple example for C++ with streaming and authentication.

# Streaming
Streaming is simple on Authify keep in mind you need premium.
```cpp
authify::license license; // This has to be authenticated before streaming.

authify::secure_image image = license.stream(); // This is still encrypted in memory
std::vector<std::uint32_t> decrypted_image = image.decrypt(128); // Your encryption key chosen on website when uploading file.
```

# Authentication
Authentication is a little bit more tricky but still very easy.
```cpp
authify::auth auth = authify::auth().init("MY_APP_ID");

authify::license license;
authify::error status = auth.authenticate("MY_LICENSE", license);
```

## Note: This only works for x64-x86 Release and libraries are built for MT (Multi-threaded)
