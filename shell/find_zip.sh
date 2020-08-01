#!/bin/bash
for i in `find /home/wangzhumo/code -name "*.sh"`
do
	tar -czf wangzhumo.tgz $i
done
