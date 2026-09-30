package com.registro.api.repositories;

import org.springframework.data.jpa.repository.JpaRepository;

import com.registro.api.entities.RegistroLed;

public interface RegistroLedRepository extends JpaRepository<RegistroLed, Long> {
	
}
