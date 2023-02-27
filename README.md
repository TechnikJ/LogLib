LogLib
=======
Library to log your projects
----------------------------


### Compile

To compile the library execute:

```
cd TriLib
mkdir build/win64
cd build/win64

cmake ../.. -G "<INSERT_BUILDSYSTEM_HERE>"
make
```

Make sure to install ``cmake,make,gcc`` for this to work.

### Documentation

Initialize the log:
>``Log(std::string Path);``

Write to log:
>``.write(std::string message, SeverityLevel Level,[std::string Code]);``
