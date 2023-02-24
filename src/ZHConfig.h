// Systems definitions for all my projects based at ZHNetwork library.
#pragma once
// ************************************************************************************************ //
typedef enum : uint8_t
{
    OPEN = 1,
    CLOSE = 0,
    ALARM = 1,
    DRY = 0
} status_type_t;
// ************************************************************************************************ //
typedef struct
{
    int16_t sensor_id{0};
    int16_t sensor_type{0};
    int16_t value_1{0};
    int16_t value_2{0};
    int16_t value_3{0};
    int16_t value_4{0};
    int16_t value_5{0};
} rf_transmitted_data_t;
// ************************************************************************************************ //
#define RF_SENSOR_TYPE                        \
    DF(RFST_NONE, "")                         \
    DF(RFST_BME280, "bme280")                 \
    DF(RFST_BMP280, "bmp280")                 \
    DF(RFST_BME680, "bme680")                 \
    DF(RFST_TOUCH_SWITCH, "touch_switch")     \
    DF(RFST_WATER_LEAKAGE, "water_leakage")   \
    DF(RFST_PLANT_HUMIDITY, "plant_humidity") \
    DF(RFST_OPEN_CLOSE, "open_close")

typedef enum : uint8_t
{
#define DF(_value, _name) _value,
    RF_SENSOR_TYPE
#undef DF
} rf_sensor_type_t;

String getValueName(rf_sensor_type_t value)
{
    switch (value)
    {
#define DF(_value, _name) \
    case _value:          \
        return _name;
        RF_SENSOR_TYPE
#undef DF
        break;
    default:
        break;
    }
    return "";
}
// ************************************************************************************************ //
#define ESP_NOW_DEVICE_TYPE                        \
    DF(ENDT_NONE, "")                              \
    DF(ENDT_GATEWAY, "espnow_gateway")             \
    DF(ENDT_SWITCH, "espnow_switch")               \
    DF(ENDT_LED, "espnow_led")                     \
    DF(ENDT_SENSOR, "espnow_sensor")               \
    DF(ENDT_RF_GATEWAY, "espnow_rf_gateway")       \
    DF(ENDT_CONTROL_PANEL, "espnow_control_panel") \
    DF(ENDT_DIMMER, "espnow_dimmer")               \
    DF(ENDT_TERRARIUM, "espnow_terrarium")         \
    DF(ENDT_RF_SENSOR, "rf_sensor")

typedef enum : uint8_t
{
#define DF(_value, _name) _value,
    ESP_NOW_DEVICE_TYPE
#undef DF
} esp_now_device_type_t;

String getValueName(esp_now_device_type_t value)
{
    switch (value)
    {
#define DF(_value, _name) \
    case _value:          \
        return _name;
        ESP_NOW_DEVICE_TYPE
#undef DF
        break;
    default:
        break;
    }
    return "";
}
// ************************************************************************************************ //
#define ESP_NOW_PAYLOAD_TYPE          \
    DF(ENPT_NONE, "")                 \
    DF(ENPT_ATTRIBUTES, "attributes") \
    DF(ENPT_KEEP_ALIVE, "status")     \
    DF(ENPT_SET, "")                  \
    DF(ENPT_STATE, "state")           \
    DF(ENPT_UPDATE, "")               \
    DF(ENPT_RESTART, "")              \
    DF(ENPT_SYSTEM, "")               \
    DF(ENPT_CONFIG, "config")         \
    DF(ENPT_FORWARD, "")

typedef enum : uint8_t
{
#define DF(_value, _name) _value,
    ESP_NOW_PAYLOAD_TYPE
#undef DF
} esp_now_payload_type_t;

String getValueName(esp_now_payload_type_t value)
{
    switch (value)
    {
#define DF(_value, _name) \
    case _value:          \
        return _name;
        ESP_NOW_PAYLOAD_TYPE
#undef DF
        break;
    default:
        break;
    }
    return "";
}
// ************************************************************************************************ //
typedef struct
{
    esp_now_device_type_t deviceType;
    esp_now_payload_type_t payloadsType;
    char message[198]{0};
} esp_now_payload_data_t;
// ************************************************************************************************ //
typedef enum : uint8_t
{
    ENLT_NONE,
    ENLT_W,
    ENLT_WW,
    ENLT_RGB,
    ENLT_RGBW,
    ENLT_RGBWW
} esp_now_led_type_t;
// ************************************************************************************************ //
typedef enum : uint8_t
{
  MCMT_NONE,
  MCMT_DEVICE_NAME,
  MCMT_DEVICE_UNIT,
  MCMT_COMPONENT_TYPE,
  MCMT_DEVICE_CLASS,
  MCMT_VALUE_TEMPLATE,
  MCMT_UNIT_OF_MEASUREMENT,
  MCMT_EXPIRE_AFTER,
  MCMT_OFF_DELAY,
  MCMT_PAYLOAD_ON,
  MCMT_PAYLOAD_OFF
} mqtt_config_message_type_t;
// ************************************************************************************************ //
#define ESP_NOW_SENSOR_TYPE     \
    DF(ENST_NONE, "")           \
    DF(ENST_DS18B20, "ds18b20") \
    DF(ENST_DHT11, "dht11")     \
    DF(ENST_DHT22, "dht22")     \
    DF(ENST_KY038, "ky-038")

typedef enum : uint8_t
{
#define DF(_value, _name) _value,
    ESP_NOW_SENSOR_TYPE
#undef DF
} esp_now_sensor_type_t;

String getValueName(esp_now_sensor_type_t value)
{
    switch (value)
    {
#define DF(_value, _name) \
    case _value:          \
        return _name;
        ESP_NOW_SENSOR_TYPE
#undef DF
        break;
    default:
        break;
    }
    return "";
}
// ************************************************************************************************ //
#define HA_COMPONENT_TYPE                               \
    DF(HACT_NONE, "")                                   \
    DF(HACT_ALARM_CONTROL_PANEL, "alarm_control_panel") \
    DF(HACT_BINARY_SENSOR, "binary_sensor")             \
    DF(HACT_BUTTON, "button")                           \
    DF(HACT_CAMERA, "camera")                           \
    DF(HACT_COVER, "cover")                             \
    DF(HACT_DEVICE_TRACKER, "device_tracker")           \
    DF(HACT_FAN, "fan")                                 \
    DF(HACT_HUMIDIFIER, "humidifier")                   \
    DF(HACT_CLIMATE_HVAC, "climate")                    \
    DF(HACT_LIGHT, "light")                             \
    DF(HACT_LOCK, "lock")                               \
    DF(HACT_NUMBER, "number")                           \
    DF(HACT_SCENE, "scene")                             \
    DF(HACT_SELECT, "select")                           \
    DF(HACT_SENSOR, "sensor")                           \
    DF(HACT_SIREN, "siren")                             \
    DF(HACT_SWITCH, "switch")                           \
    DF(HACT_UPDATE, "update")                           \
    DF(HACT_TEXT, "text")                               \
    DF(HACT_VACUUM, "vacuum")

typedef enum : uint8_t
{
#define DF(_value, _name) _value,
    HA_COMPONENT_TYPE
#undef DF
} ha_component_type_t;

String getValueName(ha_component_type_t value)
{
    switch (value)
    {
#define DF(_value, _name) \
    case _value:          \
        return _name;
        HA_COMPONENT_TYPE
#undef DF
        break;
    default:
        break;
    }
    return "";
}
// ************************************************************************************************ //
#define HA_BINARY_SENSOR_DEVICE_CLASS               \
    DF(HABSDC_NONE, "")                             \
    DF(HABSDC_BATTERY, "battery")                   \
    DF(HABSDC_BATTERY_CHARGING, "battery_charging") \
    DF(HABSDC_CARBON_MONOXIDE, "carbon_monoxide")   \
    DF(HABSDC_COLD, "cold")                         \
    DF(HABSDC_CONNECTIVITY, "connectivity")         \
    DF(HABSDC_DOOR, "door")                         \
    DF(HABSDC_GARAGE_DOOR, "garage_door")           \
    DF(HABSDC_GAS, "gas")                           \
    DF(HABSDC_HEAT, "heat")                         \
    DF(HABSDC_LIGHT, "light")                       \
    DF(HABSDC_LOCK, "lock")                         \
    DF(HABSDC_MOISTURE, "moisture")                 \
    DF(HABSDC_MOTION, "motion")                     \
    DF(HABSDC_MOVING, "moving")                     \
    DF(HABSDC_OCCUPANCY, "occupancy")               \
    DF(HABSDC_OPENING, "opening")                   \
    DF(HABSDC_PLUG, "plug")                         \
    DF(HABSDC_POWER, "power")                       \
    DF(HABSDC_PRESENCE, "presence")                 \
    DF(HABSDC_PROBLEM, "problem")                   \
    DF(HABSDC_RUNNING, "running")                   \
    DF(HABSDC_SAFETY, "safety")                     \
    DF(HABSDC_SMOKE, "smoke")                       \
    DF(HABSDC_SOUND, "sound")                       \
    DF(HABSDC_TAMPER, "tamper")                     \
    DF(HABSDC_UPDATE, "update")                     \
    DF(HABSDC_VIBRATION, "vibration")               \
    DF(HABSDC_WINDOW, "window")

typedef enum : uint8_t
{
#define DF(_value, _name) _value,
    HA_BINARY_SENSOR_DEVICE_CLASS
#undef DF
} ha_binary_sensor_device_class_t;

String getValueName(ha_binary_sensor_device_class_t value)
{
    switch (value)
    {
#define DF(_value, _name) \
    case _value:          \
        return _name;
        HA_BINARY_SENSOR_DEVICE_CLASS
#undef DF
        break;
    default:
        break;
    }
    return "";
}
// ************************************************************************************************ //
#define HA_COVER_DEVICE_CLASS    \
    DF(HACDC_NONE, "")           \
    DF(HACDC_AWNING, "awning")   \
    DF(HACDC_BLIND, "blind")     \
    DF(HACDC_CURTAIN, "curtain") \
    DF(HACDC_DAMPER, "damper")   \
    DF(HACDC_DOOR, "door")       \
    DF(HACDC_GARAGE, "garage")   \
    DF(HACDC_GATE, "gate")       \
    DF(HACDC_SHADE, "shade")     \
    DF(HACDC_SHUTTER, "shutter") \
    DF(HACDC_WINDOW, "window")

typedef enum : uint8_t
{
#define DF(_value, _name) _value,
    HA_COVER_DEVICE_CLASS
#undef DF
} ha_cover_device_class_t;

String getValueName(ha_cover_device_class_t value)
{
    switch (value)
    {
#define DF(_value, _name) \
    case _value:          \
        return _name;
        HA_COVER_DEVICE_CLASS
#undef DF
        break;
    default:
        break;
    }
    return "";
}
// ************************************************************************************************ //
#define HA_SENSOR_DEVICE_CLASS                                         \
    DF(HASDC_NONE, "")                                                 \
    DF(HASDC_APPARENT_POWER, "apparent_power")                         \
    DF(HASDC_AQI, "aqi")                                               \
    DF(HASDC_BATTERY, "battery")                                       \
    DF(HASDC_CARBON_DIOXIDE, "carbon_dioxide")                         \
    DF(HASDC_CARBON_MONOXIDE, "carbon_monoxide")                       \
    DF(HASDC_CURRENT, "current")                                       \
    DF(HASDC_DATE, "date")                                             \
    DF(HASDC_DISTANCE, "distance")                                     \
    DF(HASDC_DURATION, "duration")                                     \
    DF(HASDC_ENERGY, "energy")                                         \
    DF(HASDC_FREQUENCY, "frequency")                                   \
    DF(HASDC_GAS, "gas")                                               \
    DF(HASDC_HUMIDITY, "humidity")                                     \
    DF(HASDC_ILLUMINANCE, "illuminance")                               \
    DF(HASDC_MOISTURE, "moisture")                                     \
    DF(HASDC_MONETARY, "monetar")                                      \
    DF(HASDC_NITROGEN_DIOXIDE, "nitrogen_dioxide")                     \
    DF(HASDC_NITROGEN_MONOXIDE, "nitrogen_monoxide")                   \
    DF(HASDC_NITROUS_OXIDE, "nitrous_oxide")                           \
    DF(HASDC_OZONE, "ozone")                                           \
    DF(HASDC_PM1, "pm1")                                               \
    DF(HASDC_PM10, "pm10")                                             \
    DF(HASDC_PM25, "pm25")                                             \
    DF(HASDC_POWER_FACTOR, "power_factor")                             \
    DF(HASDC_POWER, "power")                                           \
    DF(HASDC_PRECIPITATION, "precipitation")                           \
    DF(HASDC_PRECIPITATION_INTENSITY, "precipitation_intensity")       \
    DF(HASDC_PRESSURE, "pressure")                                     \
    DF(HASDC_REACTIVE_POWER, "reactive_power")                         \
    DF(HASDC_SIGNAL_STRENGTH, "signal_strength")                       \
    DF(HASDC_SPEED, "speed")                                           \
    DF(HASDC_SULPHUR_DIOXIDE, "sulphur_dioxide")                       \
    DF(HASDC_TEMPERATURE, "temperature")                               \
    DF(HASDC_TIMESTAMP, "timestamp")                                   \
    DF(HASDC_VOLATILE_ORGANIC_COMPOUNDS, "volatile_organic_compounds") \
    DF(HASDC_VOLTAGE, "voltage")                                       \
    DF(HASDC_VOLUME, "volume")                                         \
    DF(HASDC_WATER, "water")                                           \
    DF(HASDC_WEIGHT, "weight")                                         \
    DF(HASDC_WIND_SPEED, "wind_speed")

typedef enum : uint8_t
{
#define DF(_value, _name) _value,
    HA_SENSOR_DEVICE_CLASS
#undef DF
} ha_sensor_device_class_t;

String getValueName(ha_sensor_device_class_t value)
{
    switch (value)
    {
#define DF(_value, _name) \
    case _value:          \
        return _name;
        HA_SENSOR_DEVICE_CLASS
#undef DF
        break;
    default:
        break;
    }
    return "";
}
// ************************************************************************************************ //
#define HA_SWITCH_DEVICE_CLASS  \
    DF(HASWDC_NONE, "")         \
    DF(HASWDC_OUTLET, "outlet") \
    DF(HASWDC_SWITCH, "switch")

typedef enum : uint8_t
{
#define DF(_value, _name) _value,
    HA_SWITCH_DEVICE_CLASS
#undef DF
} ha_switch_device_class_t;

String getValueName(ha_switch_device_class_t value)
{
    switch (value)
    {
#define DF(_value, _name) \
    case _value:          \
        return _name;
        HA_SWITCH_DEVICE_CLASS
#undef DF
        break;
    default:
        break;
    }
    return "";
}
// ************************************************************************************************ //