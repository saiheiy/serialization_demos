#!/usr/bin/env bash
set -x 
# MUST RUN INSIDE "[REPO ROOT]/flatbuffers/scripts" DIRECTORY, supply a sufficiently large input
if [ $# -eq 0 ]
then
    echo "No arguments supplied";
    exit 0;
fi

time ../cpp/fb_sub $1 &
#FB_SUB=$!
JAR_FILE="../java/fb-demo/target/fb-demo-1.0-SNAPSHOT-jar-with-dependencies.jar"
java -cp  $JAR_FILE com.saihei.demo.ZmqFbPublisher $1 &


set +x


