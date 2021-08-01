#ifndef __MODEL_JSON_H__
#define __MODEL_JSON_H__

const char recognition_model_string_json[] = {"{\"NumModels\":1,\"ModelIndexes\":{\"0\":\"TFu_With_SensiML_Features\"},\"ModelDescriptions\":[{\"Name\":\"TFu_With_SensiML_Features\",\"ClassMaps\":{\"1\":\"Normal\",\"2\":\"OverPronation\",\"3\":\"OverSupination\",\"4\":\"Pronation\",\"5\":\"Supination\",\"0\":\"Unknown\"},\"ModelType\":\"TFMicro\",\"FeatureFunctions\":[\"ThresholdWithOffsetCrossingRate\",\"Median\",\"Median\",\"75thPercentile\"]}]}"};

int recognition_model_string_json_len = sizeof(recognition_model_string_json);

#endif /* __MODEL_JSON_H__ */
