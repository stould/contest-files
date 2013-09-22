find ../contest-files -iname "*.o" -exec rm {} \;
find ../contest-files -iname "*.exe" -exec rm {} \;
find ../contest-files -type f -exec chmod -x {} \;
