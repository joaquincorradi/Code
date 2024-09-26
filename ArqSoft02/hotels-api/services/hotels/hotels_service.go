package hotels

import (
	"context"
	"fmt"
	"hotels-api/dao/hotels"
	hotelsDomain "hotels-api/domain/hotels"
)

type Repository interface {
	GetHotelByID(ctx context.Context, id int64) (hotels.Hotel, error)
}

type Service struct {
	mainRepository  Repository
	cacheRepository Repository
}

func NewService(mainRepository Repository, cacheRepository Repository) Service {
	return Service{
		mainRepository:  mainRepository,
		cacheRepository: cacheRepository,
	}
}

func (service Service) GetHotelByID(ctx context.Context, id int64) (hotelsDomain.Hotel, error) {
	hotelDAO, err := service.cacheRepository.GetHotelByID(ctx, id)
	if err != nil {
		fmt.Println("Not found in cache")
		// Get hotel from repository
		hotelDAO, err = service.mainRepository.GetHotelByID(ctx, id)
		if err != nil {
			return hotelsDomain.Hotel{}, fmt.Errorf("error getting hotel from repository: %v", err)
		}
		// TODO: service.cacheRepository.CreateHotel
	} else {
		fmt.Println("Found in cache")
	}

	// Convert DAO to DTO
	return hotelsDomain.Hotel{
		ID:        hotelDAO.ID,
		Name:      hotelDAO.Name,
		Address:   hotelDAO.Address,
		City:      hotelDAO.City,
		State:     hotelDAO.State,
		Rating:    hotelDAO.Rating,
		Amenities: hotelDAO.Amenities,
	}, nil
}
