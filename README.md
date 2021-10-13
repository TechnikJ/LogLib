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
>``.init(std::string Path);``

Close log safely (Optional):
>``.close();``

Write string to log:
>``.writeString(std::string content);``
