import base64
import json
import os
from google.cloud import iot_v1

def device_config(config):
    client = iot_v1.DeviceManagerClient()
    name = client.device_path(
        os.environ['PROJECT_ID'], os.environ['REGION'], os.environ['REGISTRY'],
        os.environ['DEVICE'])
    binary_data = bytes(config, 'utf-8')
    client.modify_cloud_to_device_config(name, binary_data)

def hello_pubsub(event, context):
    """Triggered from a message on a Cloud Pub/Sub topic.
    Args:
         event (dict): Event payload.
         context (google.cloud.functions.Context): Metadata for the event.
    """
    pubsub_message = base64.b64decode(event['data']).decode('utf-8')
    print(pubsub_message)
    device_config(pubsub_message)
