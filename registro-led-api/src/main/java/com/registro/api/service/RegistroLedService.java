package com.registro.api.service;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.registro.api.entities.RegistroLed;
import com.registro.api.repositories.RegistroLedRepository;


@Service
public class RegistroLedService {
	
	@Autowired
	private RegistroLedRepository repository;
	
	public List<RegistroLed> listarTodos(){
		return repository.findAll();
	}
	
	public RegistroLed salvar(RegistroLed registro) {
		return repository.save(registro);
	}
	
	public void excluir(Long id) {
		repository.deleteById(id);
	}
	

}
