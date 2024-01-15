# Iznimke

# Koristenje iznimke u funkciji "Vrijeme"

<code-block lang="c++">
void AudioPlayer::Vrijeme() {
    try {
        sf::Time lastOffset = sf::Time::Zero;
        while (!this->shouldStop && this->isPlaying && !this->isPlaybackComplete) {
            
            this->tempSekunde = static_cast<int>(this->seconds);

            if (this->shouldStop) {
                break;
            }

            if (!this->isPlaying) {
                break;
            }
            
            std::this_thread::sleep_for(std::chrono::seconds(1));
            //this->trajanjePjesme = music.getDuration().asSeconds();
            lastOffset = music.getPlayingOffset();

            this->currentTime = lastOffset;
            sf::Time playingOffset = music.getPlayingOffset();
            
            this->seconds = static_cast<int>(currentTime.asSeconds());
            this->miliseconds = static_cast<int>(currentTime.asMilliseconds());

            this->effectiveSpeed = this->brzina > 0 ? this->brzina : 1.0;
            this->seconds = static_cast<int>(currentTime.asSeconds() * effectiveSpeed);
            this->miliseconds = static_cast<int>(currentTime.asMilliseconds() * effectiveSpeed);

            // Ažurirajte trenutno vrijeme i broj uzoraka
            currentTimeInSeconds = static_cast<double>(this->seconds);
            currentSamplePosition = this->seconds * this->waveFormat.nSamplesPerSec;          
            
            {
                std::lock_guard<std::mutex> lockGuard(printMutex);
                
                    // Ispis trenutne pozicije pjesme
                //std::cout << "\rTrenutna pjesma na radiju: " << ImeFajlaBezEkstenzije(soundFilePath) << std::flush
                    //<< " ( " << this->seconds / 60 << ":" << this->seconds % 60 << " )" << std::flush;

                    //std::cout << "    >> ";
                
            }
            if (this->tempSekunde >= this->trajanjePjesme - 1 && this->ponavlja == false){
                this->isPlaybackComplete = true;
                this->shouldStop = true;
                novaPjesma();
            }
            else if (this->tempSekunde >= this->trajanjePjesme - 1 && this->ponavlja == true) {
                this->isPlaybackComplete = true;
                this->shouldStop = true;
                this->trenutniIndeksPjesme--;
                novaPjesma();
            }

        }

    }
    catch (const std::exception& e) {
        std::cerr << "Greska tokom pustanja: " << e.what() << std::endl;
        this->isPlaying = false;
        this->isPlaybackComplete = true;
    }
    catch (...) {
        std::cerr << "Nepoznata greska.\n";
        this->isPlaying = false;
        this->isPlaybackComplete = true;
        novaPjesma();
    }
}
</code-block>

# Iznimka u funckiji "novaPjesma" koja se moze naci i na "staraPjesma"

<code-block lang="c++">
void AudioPlayer::novaPjesma() {
    this->procenatBrzine = 0.5;
    this->shouldStop = true;
    this->tempSekunde = 0;
    if(this->trenutniIndeksPjesme < this->Pjesme.size() - 1)
        this->trenutniIndeksPjesme++;

    if (this->trenutniIndeksPjesme < this->Pjesme.size()) {
        try {
            this->effectiveSpeed = 1.0;
            this->brzina = 1.0;
            music.stop();
            this->stariFilePath = this->soundFilePath;
            this->soundFilePath = this->Pjesme.at(this->trenutniIndeksPjesme).getLokacijaPjesme();
            music.openFromFile(soundFilePath);
            music.setPitch(1.0);
            PromijeniBrzinuReprodukcije(1.0);
            this->pauseTime = sf::Time::Zero;
            music.play();
            this->trajanjePjesme = music.getDuration().asSeconds();
            this->isPlaying = true;
            this->isPlaybackComplete = false;
            this->shouldStop = false;
            this->seconds = 1;
            this->miliseconds = 100;

            std::thread(&AudioPlayer::Vrijeme, this).detach();
        }catch (const std::exception& e) {
            std::cerr << "Greska tokom pokretanja: " << e.what() << std::endl;
        
            this->isPlaying = false;
            this->isPlaybackComplete = true;
        }
        catch (...) {
            std::cerr << "Random greska\n";
            this->isPlaying = false;
            this->isPlaybackComplete = true;            
        }
    }
    else {
        this->isPlaying = false;
        this->isPlaybackComplete = true;
    }
}
</code-block>
