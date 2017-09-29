// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Personagem.generated.h"

/**
 * 
 */
UCLASS()
class JOGO2D_API APersonagem : public APaperCharacter
{
	GENERATED_BODY()
	
public:

	APersonagem();

	UPROPERTY (EditAnywhere) int points;

	/*Get para VidasIniciais*/
	UFUNCTION(BlueprintPure, Category = "Life") int GetVidasIniciais();

	/*Get para VidasAtuais*/
	UFUNCTION(BlueprintPure, Category = "Life") int GetVidasAtuais();

	/*Update das VidasAtuais*/
	UFUNCTION(BlueprintCallable, Category = "Life") void UpdateVidasAtuais(int Vidas);

	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(class UInputComponent*
		PlayerInputComponent) override;

	virtual void Tick(float DeltaSeconds) override;

	void UpdateFlipbook();

	UFUNCTION(BlueprintCallable, Category="Shoot")
	void StartFire();
	UFUNCTION(BlueprintCallable, Category = "Shoot")
	void StopFire();

	void AddGunToArray(class AGun* Gun);
	int GetSelectedGun();
	TArray<class AGun*> GetGuns();

private:

	/*Quantidade de vidas iniciais e também o número máximo de vidas*/
	UPROPERTY(EditAnywhere, Category = "Life") int VidasIniciais;
	/*Váriavel que segura o número de vidas atuais sem interferir nas vidas iniciais*/
	UPROPERTY(EditAnywhere, Category = "Life") int VidasAtuais;

	UPROPERTY(EditAnywhere)
		class USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere)
		class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		class UPaperFlipbook* Idle;

	UPROPERTY(EditAnywhere)
		class UPaperFlipbook* Walking;

	UPROPERTY(EditAnywhere)
		TArray<class AGun*> Guns;

	UPROPERTY(EditAnywhere)
		int SelectedGun;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HUDMobile;

	void Move(float Value);

	void TouchStarted(const ETouchIndex::Type FinderIndex,
		const FVector Location);

	void TouchStopped(const ETouchIndex::Type FinderIndex,
		const FVector Location);

	void SwitchGun();
	
};
