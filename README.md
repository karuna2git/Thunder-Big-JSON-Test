# Thunder-Big-JSON-Test
[![License](https://img.shields.io/badge/License-Apache_2.0-blue.svg)](https://opensource.org/licenses/Apache-2.0) 

This is a simple test plugin to understand and report the JSON Parsing issue that existed in WPEFramework (aka Thunder).
This TestPlugin simply publishes event every 3s. It sends a big JSON message on every 4th iteration.
The TestConsumer is something that subscribed to the above event and expected to receive all the events in order.

## Issue Reported
The TestConsumer is receiving only the 1st 3 events. The 4th will not be received but the 5th will be received but there will be a message Deserialize error reported. After that No event will be received.


