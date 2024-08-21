package dto

type Weather struct {
	Daily Daily `json:"daily"`
}

type Daily struct {
	Time               []string  `json:"time"`
	PrecipitationHours []float64 `json:"precipitation_hours"`
	PrecipitationSum   []float64 `json:"precipitation_sum"`
}
